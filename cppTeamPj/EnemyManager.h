#pragma once
#include <vector>
#include "Enemy.h"
#include <chrono>


class EnemyManager
{
private:
    std::vector<Enemy> enemies;

    float spawnTime = 1.0f;

    float spawnTimer = 0.0f;

    float moveTime = 0.05f;

    float moveTimer = 0.0f;

    std::chrono::high_resolution_clock::time_point lastUpdateTime;
    bool isFirstUpdate = true;

public:
    void EnemyUpdate();
    void SpawnEnemy();
};

