#pragma once
#include "Weapon.h"
class Granade : public Weapon
{
private:

	Vector2 middlePos;

	float time = 0.0f;
	float duration = 1.0f;
	float elapsed = 0.0f;

public:
	Granade(Scene* myScene, Vector2 originPos, Vector2 targetPos);
	virtual void Move();
};

