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
	leftTop = Vector2(parent->transform.position.x + offset.x - (width / 2), parent->transform.position.y + offset.y - (height / 2));
}

void RectangleCollider::Render()
{
	Vector2 screenPos = leftTop - parent->myScene->mainCamera->transform.position + Camera::GetScreenCenter();
	parent->myScene->GI->DrawRectangle(screenPos.x, screenPos.y, width, height, color);
}

bool RectangleCollider::CheckIfCollided(RectangleCollider* other)
{
	bool collided = false;

	if (Left() < other->Right() && Right() > other->Left() && Top() < other->Bottom() && Bottom() > other->Top()) {
		collided = true;
	}

	return collided;
}

void RectangleCollider::SetPreviousCollisions()
{
	previousCollisions = currentCollisions;
	currentCollisions.clear();
}

bool RectangleCollider::AlreadyColliding(RectangleCollider* other)
{
	return std::find(previousCollisions.begin(), previousCollisions.end(), other) != previousCollisions.end();
}
