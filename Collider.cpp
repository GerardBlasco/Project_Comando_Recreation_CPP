#include "Collider.h"

Collider::Collider(Actor* parent, float width, float height):Component(parent)
{
	this->width = width;
	this->height = height;
}

Collider::Collider(Actor* parent, float width, float height, Color color):Component(parent)
{
	this->width = width;
	this->height = height;
	this->color = color;
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
