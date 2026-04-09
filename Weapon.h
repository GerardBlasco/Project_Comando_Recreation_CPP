#pragma once
#include "Actor.h"
class Weapon : public Actor
{
private:
	int weaponDamage;
	class Vector2 targetPos;
	float speed;
	int ammo;
	int maxAmmo;
	bool infiniteAmmo;

	void Move();

public:
	Weapon(Vector2 targetPos);
	~Weapon();
};

