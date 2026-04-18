#pragma once
#include "Actor.h"
class HUD : public Actor
{
public:
	HUD(Scene* myScene);
	//virtual void Update();
	virtual void Render();
	//void HandleInput();
};

