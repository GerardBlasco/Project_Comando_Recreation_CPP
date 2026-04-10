#pragma once
#include "Component.h"
#include <iostream>

class Sprite : public Component
{
protected:
	std::string imageName;
	float height;
	float width;

public:
	Sprite(Actor* parent, std::string imgName, float width);
	Sprite(Actor* parent, std::string imgName, float width, float height);
	virtual void Update();
	virtual void Render();
};

