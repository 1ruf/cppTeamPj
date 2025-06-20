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

    timer += deltaTime;
    if (timer >= spawnTime) 
    {
        SpawnEnemy();
        timer = 0.0f;
    }

    moveTimer += deltaTime;
    if (moveTimer >= moveInterval) 
    {
        for (Enemy& enemy : enemies) 
        {
            enemy.Move();
        }
        moveTimer = 0.0f;
    }

    lastUpdateTime = currentTime;
}

void EnemyManager::SpawnEnemy()
{
    Enemy enemy;
    enemies.push_back(enemy);
}
