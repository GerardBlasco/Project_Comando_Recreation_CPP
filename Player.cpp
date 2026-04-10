#include "Player.h"
#include "Game.h"
#include "Weapon.h"
#include "Bullet.h"
#include "Granade.h"
#include "Sprite.h"
#include "InputSystem.h"
#include "Scene.h"

Player::Player(Scene* myScene):Actor(myScene)
{
	AddComponent(new Sprite(this, "player.png", 30, 50));

	transform.position.x = 40;
	transform.position.y = 40;

	// ESTO SON INPUTS
	InputSystem::Map("Horizontal")->AddListener(this, &Player::MoveHorizontal);
	InputSystem::Map("Vertical")->AddListener(this, &Player::MoveVertical);
	InputSystem::Map("PrimaryAttack")->AddListener(this, &Player::Shoot, InputEvent::Triggered);
	InputSystem::Map("SecondaryAttack")->AddListener(this, &Player::ShootAlternative, InputEvent::Triggered);
}

void Player::Update() 
{
	
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
	Weapon* bullet = new Bullet(myScene, transform.position, Vector2(InputSystem::DeltaX(), InputSystem::DeltaY()));
	myScene->LoadActor(bullet);
	std::cout << "Player Shot Primary!" << std::endl;
}

void Player::ShootAlternative()
{
	Weapon* granade = new Granade(myScene, transform.position, Vector2(InputSystem::DeltaX(), InputSystem::DeltaY()));
	myScene->LoadActor(granade);
	std::cout << "Player Shot Secondary!" << std::endl;
}
