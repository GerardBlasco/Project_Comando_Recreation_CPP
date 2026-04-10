#include "Collider.h"

Collider::Collider(Actor* parent, Vector2 center):Component(parent)
{
	this->center = center;
}
