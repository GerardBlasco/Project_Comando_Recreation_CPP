#pragma once
#include "Actor.h"
class MapChanger : public Actor
{
public:
	MapChanger(Scene* myScene);

	virtual void OnCollisionEnter(class Collider* other);

private:
	Scene* targetScene;
};

