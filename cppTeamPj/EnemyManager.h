#pragma once
#include <vector>
#include "Enemy.h"
#include <chrono>


class EnemyManager
{
private:
    // ���ʹ� ��Ƶ� ����
    std::vector<Enemy> enemies;

    // �����ð� ������ ����
    float spawnTime = 3.0f;

    // ���� �ð� ������ ����
    float timer = 0.0f;

    // ���ʸ��� �̵���ų���� ���� ����
    float moveInterval = 1.0f;

    // ���� �ð� üũ��
    float moveTimer = 0.0f;

    // std::chrono::high_resolution_clock�� ���� ���� ƽ�� �����ϰ� ������ �����̴�.
    // time_point�� Ư�� �� ������ �����Ҷ� ���� Ŭ�����̴�.
    // time_t�� �Ⱦ��� ������ �и��� ���������� ǥ���� �ȵǱ� ������ ��Ȯ���� ��������.
    std::chrono::high_resolution_clock::time_point lastUpdateTime;
    bool isFirstUpdate = true;

public:
    void EnemyUpdate();
    void SpawnEnemy();
};

