#pragma once
#include "Scene.h"
class HelpScene : public Scene
{
public:
	HelpScene(GraphicsInterface* GI);
	virtual ~HelpScene();
	virtual void HandleInput();
private:
	int selectedOption = 0;
};

