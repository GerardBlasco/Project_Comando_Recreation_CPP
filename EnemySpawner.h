#pragma once
#include "Actor.h"
#include <vector>
class EnemySpawner : public Actor
{
public:
    EnemySpawner(Scene* myScene, class Player* player);

    void Update() override;

private:
    class Player* player;
    float spawnTimer = 0.f;
    float spawnInterval = 1.5f;
    int maxEnemies = 10;

    void SpawnEnemy();
    Vector2 GetSpawnPositionOutsideCamera();
};