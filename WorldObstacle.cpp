#include "WorldObstacle.h"

WorldObstacle::WorldObstacle(Scene* myScene, Vector2 position):Actor(myScene)
{
	transform.position = position;
}
