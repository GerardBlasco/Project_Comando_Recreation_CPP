#pragma once
#include "SDL3/SDL.h"
#include "Vector2.h"
//#include "SDL3_image/SDL_image.h"
class Frame
{
public:
	SDL_FRect position;

	Frame(float x, float y, float width, float height) { position.x = x; position.y = y; position.w = width; position.h = height; }
};

