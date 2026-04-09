#include "Sprite.h"
#include "Actor.h"
#include "Scene.h"
#include "Vector2.h"
#include "InputSystem.h"

Sprite::Sprite(Actor* parent, std::string imgName, float sideSize):Component(parent)
{
	imageName = imgName;
	this->sideSize = sideSize;
}

void Sprite::Update()
{
	
}

void Sprite::Render()
{
	parent->myScene->GI->DrawSprite(imageName, parent->transform, sideSize, sideSize);
}
