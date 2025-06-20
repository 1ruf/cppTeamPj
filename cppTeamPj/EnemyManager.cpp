#include "EnemyManager.h"


void EnemyManager::EnemyUpdate()
{
    // 현재 시간을 받아서 저장하는 변수
    // std::chrono::high_resolution_clock::now();를 쓰면 현재 클록을 반환한다.
    auto currentTime = std::chrono::high_resolution_clock::now();
    float deltaTime = 0.0f;
    // 처음 update인지 체크하기
    // 만약에 안해주면 lastUpdateTime에 이상한값 들어가서 오류날 수 있다
    if (!isFirstUpdate) 
    {
        // 현재 시간과 전에 측정한 시간의 차이를 deltaTime에 넣어줌
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
        // enemy는 클래스라서 복사비용이 크니깐 참조로 넘기기
        for (Enemy& enemy : enemies) 
        {
            enemy.Move();
        }
        moveTimer = 0.0f;
    }

    // lastUpdateTime에다가 현재 시간 넣어주기
    lastUpdateTime = currentTime;
}

void EnemyManager::SpawnEnemy()
{
    Enemy enemy;
    enemies.push_back(enemy);
}
