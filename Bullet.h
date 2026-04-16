#pragma once
#include "Weapon.h"
class Bullet : public Weapon
{
protected:
	float maxDistance = 400.f;

public:
	Vector2 direction;

	Bullet(Scene* myScene, Vector2 originPos, Vector2 targetPos);
	virtual void Move();

	virtual void OnCollisionEnter(class Collider* other);
};

