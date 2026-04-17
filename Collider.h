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

public:
	Collider(Actor* parent, float width, float height);
	Collider(Actor* parent, float width, float height, Color color);
	virtual ~Collider();

	virtual void Update();

	virtual bool CheckIfCollided(Collider* other);
	void AddOffset(Vector2 offset);
};

