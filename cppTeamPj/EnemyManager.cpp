#include "EnemyManager.h"


void EnemyManager::EnemyUpdate()
{
    // ���� �ð��� �޾Ƽ� �����ϴ� ����
    // std::chrono::high_resolution_clock::now();�� ���� ���� Ŭ���� ��ȯ�Ѵ�.
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
    // emplace_back�� �����̳� ���ο��� ���� ��ü �����ڸ� �Ѱ��ش�.
    // ������ push_back�� ���� �����Ŀ� �����ϱ� ������ �������� �� emplace_back�� ����.
    enemies.emplace_back(Enemy());
}
