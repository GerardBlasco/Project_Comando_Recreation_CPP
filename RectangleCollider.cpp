#include "RectangleCollider.h"
#include "Actor.h"
#include "Scene.h"
#include <iostream>
#include "Game.h"

RectangleCollider::RectangleCollider(Actor* parent, float width, float height, bool isRigid):Collider(parent, width, height, isRigid)
{
	leftTop = Vector2(parent->transform.position.x - (width / 2), parent->transform.position.y - (height / 2));
	parent->myScene->LoadCollider(this);
}

RectangleCollider::RectangleCollider(Actor* parent, float width, float height, Color color, bool isRigid):Collider(parent, width, height, color, isRigid)
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
	if (!parent->myScene->debug) {
		return;
	}

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

Vector2 RectangleCollider::GetCenter()
{
	return Vector2(leftTop.x + (width * 0.5f), leftTop.y + (height * 0.5f));
}

void RectangleCollider::SolveCollision(RectangleCollider* other)
{
	if (IsTrigger() || other->IsTrigger()) {
		return;
	}
	
	if (!IsRigid() && !other->IsRigid()) {
		return;
	}

	float overlapLeft = other->Right() - Left();
	float overlapRight = Right() - other->Left();
	float overlapTop = other->Bottom() - Top();
	float overlapBottom = Bottom() - other->Top();

	float minOverlapX = (overlapLeft < overlapRight) ? overlapLeft : overlapRight;
	float minOverlapY = (overlapTop < overlapBottom) ? overlapTop : overlapBottom;

	Vector2 correction;

	if (minOverlapX < minOverlapY) {
		if (overlapLeft < overlapRight) {
			correction.x = overlapLeft;
		}
		else {
			correction.x = -overlapRight;
		}
	}
	else {
		if (overlapTop < overlapBottom) {
			correction.y = overlapTop;
		}
		else {
			correction.y = -overlapBottom;
		}
	}

	if (!IsRigid()) {
		parent->transform.position += correction;
	}
	else if (!other->IsRigid()) {
		other->Parent()->transform.position -= correction;
	}
}
