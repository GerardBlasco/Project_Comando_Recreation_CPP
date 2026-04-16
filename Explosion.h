#pragma once
#include "Weapon.h"

class Explosion : public Weapon
{
private:
	float time = 0.0f;
	float duration = 0.4f;
	float elapsed = 0.0f;

public:
	Explosion(Scene* myScene, Vector2 position);

	virtual void Update();
};

