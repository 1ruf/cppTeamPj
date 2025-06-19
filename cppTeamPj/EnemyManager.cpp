#include "EnemyManager.h"


void EnemyManager::EnemyUpdate()
{
    // 현재 시간을 받아서 저장하는 변수
    // std::chrono::high_resolution_clock::now();를 쓰면 현재 클록을 반환한다.
    auto currentTime = std::chrono::high_resolution_clock::now();
    float deltaTime = 0.0f;
    if (!isFirstUpdate) {
        deltaTime = std::chrono::duration<float>(currentTime - lastUpdateTime).count();
    }
    else {
        isFirstUpdate = false;
    }

    timer += deltaTime;
    if (timer >= spawnTime) {
        SpawnEnemy();
        timer = 0.0f;
    }

    moveTimer += deltaTime;
    if (moveTimer >= moveInterval) {
        for (auto& enemy : enemies) {
            enemy.Move();
        }
        moveTimer = 0.0f;
    }

    lastUpdateTime = currentTime;
}

void EnemyManager::SpawnEnemy()
{
    // emplace_back은 컨테이너 내부에서 직접 객체 생성자를 넘겨준다.
    // 하지만 push_back은 먼저 생성후에 복사하기 때문에 복사비용이 들어서 emplace_back이 좋다.
    enemies.emplace_back(Enemy());
}
