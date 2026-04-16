#include "Animation.h"
#include "Actor.h"
#include "Scene.h"
#include "SDL3_image/SDL_image.h"
#include "Game.h"

Animation::Animation(Actor* parent, std::string sheetName, int columns, int rows, float width, float height):Component(parent)
{
	this->sheetName = sheetName;
	sheetColumns = columns;
	sheetRows = rows;
	this->width = width;
	this->height = height;
}

Animation::Animation(Actor* parent, std::string sheetName, int columns, int rows, float width, float height, float frameRate):Component(parent)
{
	this->sheetName = sheetName;
	sheetColumns = columns;
	sheetRows = rows;
	this->width = width;
	this->height = height;
	this->frameRate = frameRate;
}

void Animation::LoadFrames(float x, float y, int numFrames)
{
	currentFrame = 0;
	maxFrames = numFrames;

	float width;
	float height;

	SDL_GetTextureSize(parent->myScene->GI->GetTexture(sheetName), &width, &height);

	width /= sheetColumns;
	height /= sheetRows;

	//std::cout << "Width: " << width << " | Height: " << height << std::endl;

	for (int i = 0; i < numFrames; i++) {
		frames.push_back(Frame(x + (width * i), y, width, height));
	}
}

void Animation::Render() 
{
	if (!playing) {
		return;
	}

	parent->myScene->GI->DrawSprite(sheetName, frames[currentFrame], parent->transform, width, height);

	timer += Game::DeltaTime();

	if (timer >= frameRate) {
		currentFrame++;

		if (currentFrame >= maxFrames) {
			currentFrame = 0;
		}

		timer = 0;
	}
}

void Animation::Play() 
{
	playing = true;
}

void Animation::Stop()
{
	playing = false;
}

void Animation::SetFrameRate(float frameRate)
{
	this->frameRate = frameRate;
}
