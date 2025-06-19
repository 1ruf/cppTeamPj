#pragma once
#include <vector>
#include "Enemy.h"
#include <chrono>


class EnemyManager
{
private:
    // 에너미 담아둘 벡터
    std::vector<Enemy> enemies;

    // 스폰시간 저장할 변수
    float spawnTime = 3.0f;

    // 현재 시간 저장할 변수
    float timer = 0.0f;

    // 몇초마다 이동시킬지에 대한 변수
    float moveInterval = 1.0f;

    // 현재 시간 체크용
    float moveTimer = 0.0f;

    // std::chrono::high_resolution_clock은 가장 작은 틱을 제공하고 나노초 단위이다.
    // time_point는 특정 한 시점을 저장할때 쓰는 클래스이다.
    // time_t를 안쓰는 이유는 밀리초 단위까지는 표현이 안되기 때문에 정확성이 떨어진다.
    std::chrono::high_resolution_clock::time_point lastUpdateTime;
    bool isFirstUpdate = true;

public:
    void EnemyUpdate();
    void SpawnEnemy();
};

