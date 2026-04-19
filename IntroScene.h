#pragma once
#include "Scene.h"
#include "PauseMenu.h"
class IntroScene : public Scene
{
public:
	IntroScene(GraphicsInterface* GI);
	virtual ~IntroScene();

	//PauseMenu* pauseMenu= nullptr;
};
