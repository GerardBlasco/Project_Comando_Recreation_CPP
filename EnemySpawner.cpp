#include "EnemySpawner.h"
#include "Enemy.h"
#include "Bombardier.h"
#include "Sniper.h"
#include "Game.h"
#include "Player.h"
#include "Scene.h"
#include "Parameters.h"

EnemySpawner::EnemySpawner(Scene* myScene, Player* player) : Actor(myScene)
{
    this->player = player;
}

void EnemySpawner::Update()
{
    spawnTimer += Game::DeltaTime();

    if (spawnTimer >= spawnInterval)
    {
        spawnTimer = 0.f;
        SpawnEnemy();
    }
}

Vector2 EnemySpawner::GetSpawnPositionOutsideCamera()
{
    Vector2 camPos = myScene->mainCamera->transform.position;

    float camLeft = camPos.x - Parameters::width * 0.5f;
    float camRight = camPos.x + Parameters::width * 0.5f;
    float camTop = camPos.y - Parameters::height * 0.5f;

    float minDistanceFromPlayer = 250.f; 
    float spawnOffset = 100.f;           

    Vector2 pos;

    pos.x = camLeft + rand() % (int)Parameters::width;

    pos.y = camTop - spawnOffset;

    Vector2 diff = pos - player->transform.position;
    if (diff.Module() < minDistanceFromPlayer)
    {
        return GetSpawnPositionOutsideCamera();
    }

    return pos;
}

void EnemySpawner::SpawnEnemy()
{
    int currentEnemies = 0;
    for (Actor* a : myScene->GetAllActors())
        if (a->tag == "Enemy")
            currentEnemies++;

    if (currentEnemies >= maxEnemies)
        return;

    Vector2 pos = GetSpawnPositionOutsideCamera();

    int type = rand() % 3;

    Enemy* enemy = nullptr;

    switch (type)
    {
    case 0: enemy = new Enemy(myScene, player); break;
    case 1: enemy = new Bombardier(myScene, player); break;
    case 2: enemy = new Sniper(myScene, player); break;
    }

    enemy->transform.position = pos;
    myScene->LoadActor(enemy);
}