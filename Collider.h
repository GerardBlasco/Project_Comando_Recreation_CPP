#pragma once
#include "Component.h"
#include "Transform.h"
class Collider : public Component
{
protected:
	float width;
	float height;
	class Vector2 center;

	Collider(Actor* parent, class Vector2 center);
};

