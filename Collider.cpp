#include "Collider.h"
#include "Actor.h"
#include "Game.h"

Collider::Collider(Actor* parent, float width, float height, bool isRigid):Component(parent)
{
	this->width = width;
	this->height = height;
	this->isRigid = isRigid;
}

Collider::Collider(Actor* parent, float width, float height, Color color, bool isRigid):Component(parent)
{
	this->width = width;
	this->height = height;
	this->color = color;
	this->isRigid = isRigid;
}

Collider::~Collider()
{
}

void Collider::Update()
{
	//std::cout << "Existo" << std::endl;
}

bool Collider::CheckIfCollided(Collider* other)
{
	return false;
}

void Collider::AddOffset(Vector2 offset)
{
	this->offset = offset;
}

void Collider::PushAway(Actor* other)
{
	Vector2 direction = other->transform.position - parent->transform.position;
	other->transform.position += direction.Normalized() * 250.f * Game::DeltaTime();
}

void Collider::IsRigid(bool b)
{
	isRigid = b;
}

bool Collider::IsRigid()
{
	return isRigid;
}

void Collider::IsTrigger(bool b)
{
	isTrigger = b;
}

bool Collider::IsTrigger()
{
	return isTrigger;
}
