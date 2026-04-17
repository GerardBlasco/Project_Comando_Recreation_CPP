#pragma once
#include "Actor.h"
class Pickeable : public Actor
{
public:
	Pickeable(Scene* myScene);

	virtual void OnCollisionEnter(class Collider* other);
};

