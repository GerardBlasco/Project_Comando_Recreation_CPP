#pragma once
#include "Scene.h"
class VictoryScene: public Scene
{
public:
	VictoryScene(GraphicsInterface* GI);
	~VictoryScene();
	void Update();
	void Render();
	void HandleInput();

private:
	int selectedOption;
};

