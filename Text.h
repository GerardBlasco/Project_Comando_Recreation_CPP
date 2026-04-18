#pragma once
#include "Actor.h"
#include <iostream>
class Text : public Actor
{
public:
	Text(Scene* myScene, std::string content, Vector2 position);

	virtual void Render();
	void SetContent(std::string newContent);

private:
	std::string content;
	Vector2 position;
};

