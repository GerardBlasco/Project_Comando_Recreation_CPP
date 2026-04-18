#pragma once
#include <iostream>
#include <map>
#include "Transform.h"
#include "Color.h"
#include "Frame.h"
#include "SDL3_ttf/SDL_ttf.h"

class GraphicsInterface
{
	class SDL_Window* window;
	class SDL_Renderer* renderer;

	std::map<std::string, class SDL_Texture*> imageColection;

	std::string imgPath = "Assets/Images/";
	std::string fontsPath = "Assets/Fonts/";

public:
	TTF_Font* font;

	GraphicsInterface();
	~GraphicsInterface();

	bool LoadImage(std::string path);

	bool MustWindowClose();
	SDL_Texture* GetTexture(std::string name);

	void ClearFrame();
	void DrawFrame();
	void DrawSprite(std::string imgName, Transform transform, float width, float height);
	void DrawSprite(std::string imgName, Vector2 position, float width, float height);
	void DrawSprite(std::string imgName, Frame frame, Transform transform, float width, float height);
	void DrawSprite(std::string imgName, Frame frame, Vector2 position, float width, float height);
	void DrawLine(float left, float top, float right, float bottom);
	void DrawRectangle(float left, float top, float width, float height, Color color);
	void DrawRectangle(Vector2 leftTop, float width, float height, Color color);
	void DrawText(const std::string& text, int x, int y);
};

