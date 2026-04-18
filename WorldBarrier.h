#pragma once
#include "Actor.h"
class WorldBarrier : public Actor
{
public:
	WorldBarrier(Scene* myScene, Actor* reference, Actor* target, Vector2 colliderSize, Vector2 referenceSize, bool isStatic = true);

	virtual void Update();
	void AlignRight();
	void AlignLeft();
	void AlignBottom();
	void AlignTop();

private:
	Actor* positionReference;
	Actor* followTarget;

	float colliderWidth;
	float colliderHeight;
	float referenceWidth;
	float referenceHeight;

	bool isStatic;
};

