#include "Weapon.h"
#include "Sprite.h"
#include "Game.h"

Weapon::Weapon(Scene* myScene, Vector2 originPos, Vector2 targetPos) :Actor(myScene)
{
	transform.position = originPos;
	this->originPos = originPos;
	this->targetPos = targetPos;
}

Weapon::~Weapon()
{

}

void Weapon::Update()
{
	Move();
}

void Weapon::Move()
{
	
}
