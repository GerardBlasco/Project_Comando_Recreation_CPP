#pragma once
#include "Actor.h"
class Weapon : public Actor
{
private:
	virtual void Update();
	virtual void Move();

protected:
	float speed;
	int weaponDamage;
	int ammo;
	int maxAmmo;
	bool infiniteAmmo;
	class Vector2 targetPos;
	class Vector2 originPos;

	Weapon(Scene* myScene, Vector2 originPos, Vector2 targetPos);

public:
	~Weapon();
};

