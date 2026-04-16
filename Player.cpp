#include "Player.h"
#include "Game.h"
#include "Weapon.h"
#include "Bullet.h"
#include "Granade.h"
#include "Sprite.h"
#include "RectangleCollider.h"
#include "Animation.h"
#include "InputSystem.h"
#include "Scene.h"
#include "Color.h"
#include "Animator.h"

Player::Player(Scene* myScene):Actor(myScene)
{
	AddComponent(new RectangleCollider(this, 40, 40, Color(0, 0, 255, 255)));

	/*Animation* animationDown = new Animation(this, "enemy2.png", 6, 8, 40, 40);
	animationDown->LoadFrames(0, 0, 4);

	Animation* animationIdleDown = new Animation(this, "enemy2.png", 6, 8, 40, 40);
	animationIdleDown->LoadFrames(96, 0, 2);
	animationIdleDown->SetFrameRate(0.5f);

	Animation* animationUp = new Animation(this, "enemy2.png", 6, 8, 40, 40);
	animationUp->LoadFrames(0, 44, 4);

	Animation* animationIdleUp = new Animation(this, "enemy2.png", 6, 8, 40, 40);
	animationIdleUp->LoadFrames(96, 44, 2);
	animationIdleUp->SetFrameRate(0.5f);

	Animation* animationLeft = new Animation(this, "enemy2.png", 6, 8, 40, 40);
	animationLeft->LoadFrames(0, 88, 4);

	Animation* animationIdleLeft = new Animation(this, "enemy2.png", 6, 8, 40, 40);
	animationIdleLeft->LoadFrames(96, 88, 2);
	animationIdleLeft->SetFrameRate(0.5f);

	Animation* animationRight = new Animation(this, "enemy2.png", 6, 8, 40, 40);
	animationRight->LoadFrames(0, 132, 4);

	Animation* animationIdleRight = new Animation(this, "enemy2.png", 6, 8, 40, 40);
	animationIdleRight->LoadFrames(96, 132, 2);
	animationIdleRight->SetFrameRate(0.5f);

	Animation* animationDownLeft = new Animation(this, "enemy2.png", 6, 8, 40, 40);
	animationDownLeft->LoadFrames(0, 176, 4);

	Animation* animationIdleDownLeft = new Animation(this, "enemy2.png", 6, 8, 40, 40);
	animationIdleDownLeft->LoadFrames(96, 176, 2);
	animationIdleDownLeft->SetFrameRate(0.5f);

	Animation* animationDownRight = new Animation(this, "enemy2.png", 6, 8, 40, 40);
	animationDownRight->LoadFrames(0, 220, 4);

	Animation* animationIdleDownRight = new Animation(this, "enemy2.png", 6, 8, 40, 40);
	animationIdleDownRight->LoadFrames(96, 220, 2);
	animationIdleDownRight->SetFrameRate(0.5f);

	Animation* animationUpLeft = new Animation(this, "enemy2.png", 6, 8, 40, 40);
	animationUpLeft->LoadFrames(0, 264, 4);

	Animation* animationIdleUpLeft = new Animation(this, "enemy2.png", 6, 8, 40, 40);
	animationIdleUpLeft->LoadFrames(96, 264, 2);
	animationIdleUpLeft->SetFrameRate(0.5f);

	Animation* animationUpRight = new Animation(this, "enemy2.png", 6, 8, 40, 40);
	animationUpRight->LoadFrames(0, 308, 4);

	Animation* animationIdleUpRight = new Animation(this, "enemy2.png", 6, 8, 40, 40);
	animationIdleUpRight->LoadFrames(96, 308, 2);
	animationIdleUpRight->SetFrameRate(0.5f);

	animator = new Animator(this);
	animator->LoadAnimation(animationDown, "Walk Down");
	animator->LoadAnimation(animationUp, "Walk Up");
	animator->LoadAnimation(animationLeft, "Walk Left");
	animator->LoadAnimation(animationRight, "Walk Right");
	animator->LoadAnimation(animationDownLeft, "Walk Down Left");
	animator->LoadAnimation(animationDownRight, "Walk Down Right");
	animator->LoadAnimation(animationUpLeft, "Walk Up Left");
	animator->LoadAnimation(animationUpRight, "Walk Up Right");
	animator->LoadAnimation(animationIdleDown, "Idle Down");
	animator->LoadAnimation(animationIdleUp, "Idle Up");
	animator->LoadAnimation(animationIdleLeft, "Idle Left");
	animator->LoadAnimation(animationIdleRight, "Idle Right");
	animator->LoadAnimation(animationIdleDownLeft, "Idle Down Left");
	animator->LoadAnimation(animationIdleDownRight, "Idle Down Right");
	animator->LoadAnimation(animationIdleUpLeft, "Idle Up Left");
	animator->LoadAnimation(animationIdleUpRight, "Idle Up Right");*/

	animator = new Animator(this);
	AddComponent(animator);

	animator->GenerateAnimationsRange("player.png", "Walk", order, 0, 0, 6, 8, 4, 40.f, 40.f);
	animator->GenerateAnimationsRange("player.png", "Idle", order, 96, 0, 6, 8, 2, 40.f, 40.f, 0.5f);

	//animator->PlayAnimation("WalkUp");

	tag = "Player";

	transform.position.x = 60;
	transform.position.y = 60;


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

	Vector2 mouseDirection = mousePosition - transform.position;

	currentIndex = DirectionIndex(mouseDirection);

	std::string animationName;

	if (isMoving) {
		animationName = "Walk" + directions[currentIndex];
	}
	else {
		animationName = "Idle" + directions[currentIndex];
	}

	//animationName = "Walk" + directions[currentIndex];

	if (currentAnimation != animationName) {
		currentAnimation = animationName;
		animator->PlayAnimation(currentAnimation);
	}

	/*if (index != currentIndex)
	{
		currentIndex = index;

		switch (currentIndex) {
		case 0:
			animator->PlayAnimation("Walk Right");
			break;
		case 1:
			animator->PlayAnimation("Walk Down Right");
			break;
		case 2:
			if (isMoving) {
				animator->PlayAnimation("Walk Down");
			}
			else {
				animator->PlayAnimation("Idle Down");
			}
			break;
		case 3:
			animator->PlayAnimation("Walk Down Left");
			break;
		case 4:
			animator->PlayAnimation("Walk Left");
			break;
		case 5:
			animator->PlayAnimation("Walk Up Left");
			break;
		case 6:
			animator->PlayAnimation("Walk Up");
			break;
		case 7:
			animator->PlayAnimation("Walk Up Right");
			break;
		}
	}*/
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
	//std::cout << "Player Shot Primary!" << std::endl;
}

void Player::ShootAlternative()
{
	Weapon* granade = new Granade(myScene, transform.position, Vector2(InputSystem::DeltaX(), InputSystem::DeltaY()));
	myScene->LoadActor(granade);
	//std::cout << "Player Shot Secondary!" << std::endl;
}

int Player::DirectionIndex(Vector2 direction)
{
	float angle = atan2(direction.y, direction.x);
	float degrees = angle * (180.0f / 3.14159265f);

	if (degrees < 0) degrees += 360.0f;

	int index = (int)((degrees + 22.5f) / 45.0f) % 8;

	return index;
}
