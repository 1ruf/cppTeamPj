#include "EnemyManager.h"


void EnemyManager::EnemyUpdate()
{
    auto currentTime = std::chrono::high_resolution_clock::now();
    float deltaTime = 0.0f;
    if (!isFirstUpdate) 
    {
        deltaTime = std::chrono::duration<float>(currentTime - lastUpdateTime).count();
    }
    else 
    {
        isFirstUpdate = false;
    }

    spawnTimer += deltaTime;
    if (spawnTimer >= spawnTime) 
    {
        SpawnEnemy();
        spawnTimer = 0.0f;
    }

    moveTimer += deltaTime;
    if (moveTimer >= moveTime) 
    {
        for (Enemy& enemy : enemies) 
        {
            if (!enemy.CheckShield())
            {
                enemy.Move();   
            }
        }
        moveTimer = 0.0f;
    }

    lastUpdateTime = currentTime;
}

void EnemyManager::SpawnEnemy()
{
    for (int i = 0; i < 3; ++i)
    {
        enemies.emplace_back();
    }
}
