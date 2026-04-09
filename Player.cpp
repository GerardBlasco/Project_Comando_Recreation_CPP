#include "Player.h"
#include "Weapon.h"
#include "Sprite.h"
#include "InputSystem.h"

Player::Player(Scene* myScene):Actor(myScene)
{
	AddComponent(new Sprite(this, "UFO.png", 100));

	// ESTO SON INPUTS
	InputSystem::Map("Horizontal")->AddListener(this, &Player::MoveHorizontal);
	InputSystem::Map("Vertical")->AddListener(this, &Player::MoveVertical);
}

void Player::MoveHorizontal()
{
	transform.position.x += InputSystem::Map("Horizontal")->ReadFloat() * 0.1f;
}

void Player::MoveVertical()
{
	transform.position.y += InputSystem::Map("Vertical")->ReadFloat() * 0.1f;
}
