#pragma once
#include "Scene.h"
#include "GraphicsInterface.h"
class HUD
{
public:
	HUD(GraphicsInterface* GI);
	~HUD();
	void Update();
	void Render();
	void HandleInput();

	GraphicsInterface* GI;
};

