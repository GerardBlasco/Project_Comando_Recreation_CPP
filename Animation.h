#pragma once
#include "Component.h"
#include "Frame.h"
#include <vector>
#include <iostream>

class Animation : public Component
{
private:
	std::vector<Frame> frames;
	std::string sheetName;
	int currentFrame, maxFrames;
	int sheetColumns, sheetRows;

	float width, height;

	float timer = 0;

	float frameRate = 0.1f;

	bool playing = true;

public:
	Animation(Actor* parent, std::string sheetName, int columns, int rows, float width, float height);
	Animation(Actor* parent, std::string sheetName, int columns, int rows, float width, float height, float frameRate);
	void LoadFrames(float x, float y, int numFrames);

	virtual void Render();
	void Play();
	void Stop();

	void SetFrameRate(float frameRate);
};

