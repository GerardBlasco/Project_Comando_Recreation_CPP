#pragma once
#include "MapChanger.h"

class VictoryChanger : public MapChanger
{
public:
	VictoryChanger(Scene* myScene);

	virtual void OnCollisionEnter(class Collider* other);
};

