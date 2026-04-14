#pragma once
#include "Scene.h"
class HelpScene: public Scene
{
public:
	HelpScene(GraphicsInterface* GI);
	~HelpScene();
	void Update();
	void Render();
	void HandleInput();
private:
	int selectedOption;
};

