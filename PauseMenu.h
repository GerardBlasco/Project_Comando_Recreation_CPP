#pragma once
#include "Actor.h"
#include "Scene.h"

class PauseMenu: public Actor
{
public:
	PauseMenu(Scene* scene);

	virtual void Update();
	virtual void Render();

	virtual void HandleInputs();
	virtual void ShowCanvas();

	bool active = false;

private:
	int selectedOption = 0;

	class Text* menuOption1;
	class Text* menuOption2;

	
};

