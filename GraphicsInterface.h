#pragma once
#include <iostream>
#include <map>
#include "Transform.h"

class GraphicsInterface
{
	class SDL_Window* window;
	class SDL_Renderer* renderer;

	std::map<std::string, class SDL_Texture*> imageColection;

public:
	GraphicsInterface();
	~GraphicsInterface();

	bool LoadImage(std::string path);

	bool MustWindowClose();

	void ClearFrame();
	void DrawFrame();
	void DrawSprite(std::string imgName, Transform transform, float width, float height);
};

