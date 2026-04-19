#include "ObstacleData.h"

static const ObstacleData OBSTACLE_CATALOG[] = {
    ObstacleData(0, "", Vector2(0, 0)),
    ObstacleData(1, "palmtree.png", Vector2(70, 100))
};

static const int OBSTACLE_COUNT = sizeof(OBSTACLE_CATALOG) / sizeof(ObstacleData);

const ObstacleData& ObstacleData::Get(int id)
{
    return OBSTACLE_CATALOG[id];
}

int ObstacleData::Count()
{
    return OBSTACLE_COUNT;
}