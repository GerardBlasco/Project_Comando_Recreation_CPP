#include "RectangleCollider.h"

RectangleCollider::RectangleCollider(Actor* parent, Vector2 center, Vector2 topLeft):Collider(parent, center)
{
	this->topLeft = topLeft;
}
