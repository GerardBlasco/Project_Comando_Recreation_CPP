#pragma once
#include "Collider.h"

class RectangleCollider : public Collider
{
public:
	Vector2 leftTop;

	RectangleCollider(Actor* parent, float width, float height);
	RectangleCollider(Actor* parent, float width, float height, Color color);
	~RectangleCollider();

	virtual void Update();
	virtual void Render();

	virtual bool CheckIfCollided(RectangleCollider* other);

private:
	inline float Left() { return leftTop.x; }
	inline float Right() { return leftTop.x + width; }
	inline float Top() { return leftTop.y; }
	inline float Bottom() { return leftTop.y + height; }
};

