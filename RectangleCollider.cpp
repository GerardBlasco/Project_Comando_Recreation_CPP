#include "RectangleCollider.h"
#include "Actor.h"
#include "Scene.h"
#include <iostream>

RectangleCollider::RectangleCollider(Actor* parent, float width, float height):Collider(parent, width, height)
{
	leftTop = Vector2(parent->transform.position.x - (width / 2), parent->transform.position.y - (height / 2));
	parent->myScene->LoadCollider(this);
}

RectangleCollider::RectangleCollider(Actor* parent, float width, float height, Color color):Collider(parent, width, height, color)
{
	leftTop = Vector2(parent->transform.position.x - (width / 2), parent->transform.position.y - (height / 2));
	parent->myScene->LoadCollider(this);
}

RectangleCollider::~RectangleCollider()
{
	parent->myScene->RemoveCollider(this);
}

void RectangleCollider::Update()
{
	leftTop = Vector2(parent->transform.position.x - (width / 2), parent->transform.position.y - (height / 2));
}

void RectangleCollider::Render()
{
	parent->myScene->GI->DrawRectangle(leftTop.x, leftTop.y, width, height, color);
}

bool RectangleCollider::CheckIfCollided(RectangleCollider* other)
{
	bool collided = false;

	if (Left() < other->Right() && Right() > other->Left() && Top() < other->Bottom() && Bottom() > other->Top()) {
		collided = true;
	}

	return collided;
}
