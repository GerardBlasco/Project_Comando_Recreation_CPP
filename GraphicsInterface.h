#pragma once
#include <iostream>
#include <map>
#include "Transform.h"
#include "SDL3_ttf/SDL_ttf.h"


class GraphicsInterface
{
	class SDL_Window* window;
	class SDL_Renderer* renderer;
	 

	std::map<std::string, class SDL_Texture*> imageColection;

public:
	TTF_Font* font;

	GraphicsInterface();
	~GraphicsInterface();

	bool LoadImage(std::string path);

	bool MustWindowClose();

	void ClearFrame();
	void DrawFrame();
	void DrawSprite(std::string imgName, Transform transform, float width, float height);
	void DrawText(const std::string& text, int x, int y);
};

