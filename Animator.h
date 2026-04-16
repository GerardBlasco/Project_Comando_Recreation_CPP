#pragma once
#include "Component.h"
#include <iostream>
#include <map>
#include <vector>

class Animator : public Component
{
private:
	std::map<std::string, class Animation*> animations;
	class Animation* currentAnimation;

public:
	Animator(Actor* parent);

	void LoadAnimation(std::string name, class Animation* animation);
	void PlayAnimation(std::string name);

	virtual void Render();

	class Animation* CreateAnimation(std::string sheetName, int x, int y, int columns, int rows, int numFrames, float width, float height, float frameRate);
	void GenerateAnimationsRange(std::string sheetName, std::string state, std::vector<std::string> names, int x, int y, int columns, int rows, int numFrames, float width, float height, float frameRate = 0.1f);
};

