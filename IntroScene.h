#pragma once
#include "Scene.h"
#include "HUD.h"
class IntroScene : public Scene
{
public:
	IntroScene(GraphicsInterface* GI);
	void Update();
	void Render();

	HUD* hud;
};

