#pragma once
#include "Scene.h"
class CreditsScene : public Scene
{
public:
	CreditsScene(GraphicsInterface* GI);
	virtual ~CreditsScene();
	virtual void HandleInput();

private:
	int selectedOption = 0;
};

