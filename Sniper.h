#pragma once
#include "Enemy.h"
class Sniper : public Enemy
{
public:
	Sniper(Scene* myScene, class Player* target);

	virtual void Update();

	virtual void OnCollisionEnter(Collider* other);

protected:
	virtual void SeekDirection();
};

