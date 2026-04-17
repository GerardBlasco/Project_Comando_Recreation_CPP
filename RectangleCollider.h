#pragma once
#include "Collider.h"
#include <vector>

class RectangleCollider : public Collider
{
public:
	std::vector<RectangleCollider*> currentCollisions;
	std::vector<RectangleCollider*> previousCollisions;

	Vector2 leftTop;

	RectangleCollider(Actor* parent, float width, float height);
	RectangleCollider(Actor* parent, float width, float height, Color color);
	~RectangleCollider();

	virtual void Update();
	virtual void Render();

	virtual bool CheckIfCollided(RectangleCollider* other);

	void SetPreviousCollisions();
	bool AlreadyColliding(RectangleCollider* other);

private:
	inline float Left() { return leftTop.x; }
	inline float Right() { return leftTop.x + width; }
	inline float Top() { return leftTop.y; }
	inline float Bottom() { return leftTop.y + height; }
};

