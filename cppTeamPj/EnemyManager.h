#pragma once
#include <vector>
#include "PlayerEnemy.h"
#include "ShieldEnemy.h"
#include "Player.h"
#include <chrono>
#include "ScoreManager.h"

class EnemyManager
{
private:
    std::vector<PlayerEnemy> playerEnemies;
    std::vector<ShieldEnemy> shieldEnemies;

    float spawnTime = 1.0f;
    float defaultSpawnTime = 1.0f;

    float spawnTimer = 0.0f;

    float moveTime = 0.04f;
    float defaultMoveTime = 0.04f;

    float moveTimer = 0.0f;

    float spawnDownHigh = 0.0051f;
    float moveDownHigh = 0.00012f;
    float spawnDownLow = 0.0022f;
    float moveDownLow = 0.00004f;

    int DifficultyLevelPoint = 90;

    std::chrono::high_resolution_clock::time_point lastUpdateTime;

    void LevelUp(ScoreManager& scoreManager);

public:
    void EnemyUpdate(ScoreManager& scoreManager, Player& player);
    void SpawnEnemy();
    void DownSpawnTime(float downTime);
    void DownMoveTime(float downTime);
    void Initialize();
};

