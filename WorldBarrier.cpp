#include "WorldBarrier.h"
#include "RectangleCollider.h"

WorldBarrier::WorldBarrier(Scene* myScene, Actor* reference, Actor* target, Vector2 colliderSize, Vector2 referenceSize, bool isStatic) :Actor(myScene)
{
	followTarget = target;
	positionReference = reference;

	colliderWidth = colliderSize.x;
	colliderHeight = colliderSize.y;

	referenceWidth = referenceSize.x;
	referenceHeight = referenceSize.y;

	this->isStatic = isStatic;

	AddComponent(new RectangleCollider(this, colliderWidth, colliderHeight, Color(255, 0, 0, 255), true));
}

void WorldBarrier::Update()
{
	if (isStatic) {
		return;
	}

	float targetHeight = followTarget->transform.position.y;
	transform.position.y = targetHeight;
}

void WorldBarrier::AlignRight()
{
	transform.position.x = positionReference->transform.position.x + (referenceWidth + colliderWidth) * 0.5f;
}

void WorldBarrier::AlignLeft()
{
	transform.position.x = positionReference->transform.position.x - (referenceWidth + colliderWidth) * 0.5f;
}

void WorldBarrier::AlignBottom()
{
	transform.position.x = positionReference->transform.position.x;
	transform.position.y = positionReference->transform.position.y + (referenceHeight + colliderHeight) * 0.5f;
}

void WorldBarrier::AlignTop()
{
	transform.position.x = positionReference->transform.position.x;
	transform.position.y = positionReference->transform.position.y - (referenceHeight + colliderHeight) * 0.5f;
}
