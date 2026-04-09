#pragma once
#include "Component.h"
#include <iostream>

class Sprite : public Component
{
protected:
	std::string imageName;
	float sideSize;

public:
	Sprite(Actor* parent, std::string imgName, float sideSize);
	virtual void Update();
	virtual void Render();
};

