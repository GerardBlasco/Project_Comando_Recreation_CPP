#pragma once
#include "Actor.h"
class WorldObstacle : public Actor
{
public:
	WorldObstacle(Scene* myScene, std::string sprite, Vector2 position, Vector2 size);
};

