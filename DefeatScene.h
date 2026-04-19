#pragma once
#include "Scene.h"
#include "GraphicsInterface.h"

class DefeatScene: public Scene
{
public:
	DefeatScene(GraphicsInterface* GI);
	virtual ~DefeatScene();
	virtual void HandleInput();
	virtual void ChangeToScene();

private:
	int selectedOption = 0;

	class Text* menuOption1;
	class Text* menuOption2;


};

