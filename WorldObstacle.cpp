#include "WorldObstacle.h"
#include "Sprite.h"
#include "RectangleCollider.h"

WorldObstacle::WorldObstacle(Scene* myScene, std::string sprite, Vector2 position, Vector2 size):Actor(myScene)
{
	transform.position = position;

	AddComponent(new Sprite(this, sprite, size.x, size.y));
}
