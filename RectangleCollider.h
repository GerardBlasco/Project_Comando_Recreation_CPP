#pragma once
#include "Collider.h"

class RectangleCollider : public Collider
{
public:
	class Vector2 topLeft;

	RectangleCollider(Actor* parent, class Vector2 center, class Vector2 topLeft);

private:
	float Left();
	float Right();
	float Top();
	float Bottom();
};

