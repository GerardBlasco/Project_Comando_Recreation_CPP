#pragma once
#include "Scene.h"
class CreditsScene: public Scene
{
public:
	CreditsScene(GraphicsInterface* GI);
	~CreditsScene();
	void Update();
	void Render();
	void HandleInput();

private:
	int selectedOption;

};

