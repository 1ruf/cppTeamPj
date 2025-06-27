#pragma once
#include <vector>
#include "Enemy.h"
#include "Player.h"
#include <chrono>
#include "ScoreManager.h"

class EnemyManager
{
private:
    std::vector<Enemy> enemies;

    float spawnTime = 1.0f;

    float spawnTimer = 0.0f;

    float moveTime = 0.04f;

    float moveTimer = 0.0f;

    std::chrono::high_resolution_clock::time_point lastUpdateTime;
    bool isFirstUpdate = true;

public:
    void EnemyUpdate(ScoreManager& scoreManager, Player& player);
    void SpawnEnemy();
    void DownSpawnTime(float downTime);
    void DownMoveTime(float downTime);
};

