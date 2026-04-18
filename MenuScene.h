#pragma once
#include "Scene.h"
class MenuScene : public Scene
{
public:
	MenuScene(GraphicsInterface* GI);
	virtual ~MenuScene();
	virtual void HandleInput();
	virtual void ChangeToScene();

private:
	int selectedOption = 0;
	class Text* menuOption1;
	class Text* menuOption2;
	class Text* menuOption3;
	class Text* menuOption4;
};

