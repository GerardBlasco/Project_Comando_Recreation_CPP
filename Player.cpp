#include "Player.h"
#include "Game.h"
#include "Weapon.h"
#include "Bullet.h"
#include "Granade.h"
#include "Sprite.h"
#include "RectangleCollider.h"
#include "Parameters.h"
#include "Animation.h"
#include "InputSystem.h"
#include "Scene.h"
#include "Color.h"
#include "Animator.h"

Player::Player(Scene* myScene):Actor(myScene)
{
	AddComponent(new RectangleCollider(this, 40, 40, Color(0, 0, 255, 255)));

	animator = new Animator(this);
	AddComponent(animator);

	std::map<int, std::string> directions = 
	{ 
		{0, "Right"}, 
		{1, "DownRight"}, 
		{2, "Down"}, 
		{3, "DownLeft"}, 
		{4, "Left"}, 
		{5, "UpLeft"}, 
		{6, "Up"}, 
		{7, "UpRight"} 
	};

	std::vector<std::string> sheetOrder = 
	{ 
		"Down", 
		"Up", 
		"Left", 
		"Right", 
		"DownLeft", 
		"DownRight", 
		"UpLeft", 
		"UpRight" 
	};

	animator->GenerateAnimationsRange("player.png", "Walk", sheetOrder, 0, 0, 6, 8, 4, 40.f, 40.f);
	animator->GenerateAnimationsRange("player.png", "Idle", sheetOrder, 96, 0, 6, 8, 2, 40.f, 40.f, 0.5f);
	animator->LoadDirectionsOrder(directions);

	tag = "Player";

	transform.position = Vector2(Parameters::width * 0.5f, Parameters::height * 0.5f);

	// ESTO SON INPUTS
	InputSystem::Map("Horizontal")->AddListener(this, &Player::MoveHorizontal);
	InputSystem::Map("Vertical")->AddListener(this, &Player::MoveVertical);
	InputSystem::Map("PrimaryAttack")->AddListener(this, &Player::Shoot, InputEvent::Triggered);
	InputSystem::Map("SecondaryAttack")->AddListener(this, &Player::ShootAlternative, InputEvent::Triggered);
}

void Player::Update() 
{
	bool isMoving = InputSystem::Map("Horizontal")->performed || InputSystem::Map("Vertical")->performed;

	Vector2 mousePosition(InputSystem::DeltaX(), InputSystem::DeltaY());

	Vector2 mouseWorldPosition = Camera::ScreenToWorld(mousePosition, myScene->mainCamera);
	Vector2 mouseDirection = mouseWorldPosition - transform.position;

	animator->SetCurrentIndex(Vector2::DirectionIndex(mouseDirection, 8));

	std::string animationName;

	if (isMoving) {
		animationName = "Walk" + animator->GetDirection(animator->GetCurrentIndex());
	}
	else {
		animationName = "Idle" + animator->GetDirection(animator->GetCurrentIndex());
	}

	if (animator->GetCurrentAnimationName() != animationName) {
		animator->SetCurrentAnimationName(animationName);
		animator->PlayAnimation(animationName);
	}
}

void Player::MoveHorizontal()
{
	transform.position.x += InputSystem::Map("Horizontal")->ReadFloat() * 200.f * Game::DeltaTime();
}

void Player::MoveVertical()
{
	transform.position.y += InputSystem::Map("Vertical")->ReadFloat() * 200.f * Game::DeltaTime();
}

void Player::Shoot()
{
	Vector2 mouseWorldPosition = Camera::ScreenToWorld(Vector2(InputSystem::DeltaX(), InputSystem::DeltaY()), myScene->mainCamera);

	Weapon* bullet = new Bullet(myScene, transform.position, mouseWorldPosition);
	myScene->LoadActor(bullet);
}

void Player::ShootAlternative()
{
	Vector2 mouseWorldPosition = Camera::ScreenToWorld(Vector2(InputSystem::DeltaX(), InputSystem::DeltaY()), myScene->mainCamera);

	Weapon* granade = new Granade(myScene, transform.position, mouseWorldPosition);
	myScene->LoadActor(granade);
}
