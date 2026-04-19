#include "Weapon.h"
#include "Sprite.h"
#include "Game.h"

Weapon::Weapon(Scene* myScene, Vector2 originPos, Vector2 targetPos) :Actor(myScene)
{
	transform.position = originPos;
	this->originPos = originPos;
	this->targetPos = targetPos;

	tag = "Attack";
}

void Weapon::SetSpeed(float speed)
{
	this->speed = speed;
}

void Weapon::HitTag(std::string hitTag)
{
	this->hitTag = hitTag;
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
