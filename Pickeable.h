#pragma once
#include "Actor.h"
#include "Player.h"
class Pickeable : public Actor
{
public:
	Pickeable(Scene* myScene, Player* target);

	virtual void OnCollisionEnter(class Collider* other);

	Player* player; //puntero al player
};

