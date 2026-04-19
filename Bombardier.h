#pragma once
#include "Enemy.h"
class Bombardier : public Enemy
{
public:
	Bombardier(class Scene* myScene, class Player* target);

	virtual void Update();

	virtual void OnCollisionEnter(Collider* other);
};

