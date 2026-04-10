#include "Sprite.h"
#include "Actor.h"
#include "Scene.h"
#include "Vector2.h"
#include "InputSystem.h"

Sprite::Sprite(Actor* parent, std::string imgName, float width):Component(parent)
{
	imageName = imgName;
	this->width = width;
	this->height = width;
}

Sprite::Sprite(Actor* parent, std::string imgName, float width, float height) :Component(parent)
{
	imageName = imgName;
	this->width = width;
	this->height = height;
}

void Sprite::Update()
{
	
}

void Sprite::Render()
{
	parent->myScene->GI->DrawSprite(imageName, parent->transform, width, height);
}
