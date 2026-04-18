#pragma once
#include "Collider.h"
#include <vector>

class RectangleCollider : public Collider
{
public:
	std::vector<RectangleCollider*> currentCollisions;
	std::vector<RectangleCollider*> previousCollisions;

	Vector2 leftTop;

	RectangleCollider(Actor* parent, float width, float height, bool isRigid = false);
	RectangleCollider(Actor* parent, float width, float height, Color color, bool isRigid = false);
	~RectangleCollider();

	virtual void Update();
	virtual void Render();

	virtual bool CheckIfCollided(RectangleCollider* other);

	void SetPreviousCollisions();
	bool AlreadyColliding(RectangleCollider* other);
	Vector2 GetCenter();

	void SolveCollision(RectangleCollider* other);

	inline float Left() { return leftTop.x; }
	inline float Right() { return leftTop.x + width; }
	inline float Top() { return leftTop.y; }
	inline float Bottom() { return leftTop.y + height; }
private:
};

