#pragma once
#include "Component.h"
#include "Transform.h"
#include "Color.h"
#include <iostream>
#include <vector>

class Collider : public Component
{
protected:
	float width = 100.f;
	float height = 100.f;
	Color color {};
	Vector2 offset;

	bool isRigid = false;
	bool isTrigger = false;
public:
	Collider(Actor* parent, float width, float height, bool isRigid = false);
	Collider(Actor* parent, float width, float height, Color color, bool isRigid = false);
	virtual ~Collider();

	virtual void Update();

	virtual bool CheckIfCollided(Collider* other);
	void AddOffset(Vector2 offset);

	void PushAway(Actor* other);

	void IsRigid(bool b);
	bool IsRigid();
	void IsTrigger(bool b);
	bool IsTrigger();
};

