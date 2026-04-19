#pragma once
#include "Scene.h"

class VictoryScene : public Scene
{
public:
	VictoryScene(GraphicsInterface* GI);
	//virtual ~VictoryScene();
	virtual void Inputs();
	virtual void ChangeScenes();

private:
	int selectedOption = 0;

	class Text* menuOption1;
	class Text* menuOption2;
};