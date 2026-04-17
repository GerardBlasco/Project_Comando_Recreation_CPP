#include "Map.h"
#include "Parameters.h"

Map::Map(Scene* myScene):Actor(myScene)
{
	transform.position = Vector2(Parameters::width * 0.5f, Parameters::height * 0.5f);
}
