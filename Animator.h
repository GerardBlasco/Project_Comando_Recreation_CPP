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
	int currentIndex = 0;
	std::string currentAnimationName;

	std::map<int, std::string> directions;

public:
	Animator(Actor* parent);
	~Animator();

	void LoadAnimation(std::string name, class Animation* animation);
	void PlayAnimation(std::string name);
	void SetCurrentIndex(int index);
	int GetCurrentIndex();

	virtual void Render();
	std::map<std::string, class Animation*> Animations();

	void LoadDirectionsOrder(std::map<int, std::string> orderedDirections);
	std::string GetDirection(int id);
	std::string GetCurrentAnimationName();
	void SetCurrentAnimationName(std::string name);

	class Animation* CreateAnimation(std::string sheetName, int x, int y, int columns, int rows, int numFrames, float width, float height, float frameRate);
	void GenerateAnimationsRange(std::string sheetName, std::string state, std::vector<std::string> names, int x, int y, int columns, int rows, int numFrames, float width, float height, float frameRate = 0.1f);
};

