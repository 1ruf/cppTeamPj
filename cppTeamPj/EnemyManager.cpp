#include "EnemyManager.h"

void EnemyManager::EnemyUpdate(ScoreManager& scoreManager, Player& player)
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
		for (auto enemy = enemies.begin(); enemy != enemies.end(); )
		{
			if (enemy->CheckShield())
			{
				scoreManager.ScoreUp(1);
				enemy = enemies.erase(enemy);
			}
			else if (enemy->CheckPlayer(player.GetPosition()))
			{
				player.Hit();
				enemy = enemies.erase(enemy);
			}
			else
			{
				enemy->Move();
				++enemy;
			}
		}
		moveTimer = 0.0f;
	}

	lastUpdateTime = currentTime;
}

void EnemyManager::SpawnEnemy()
{
	int arr[4] = {};
	for (int i = 0; i < 4; ++i)
	{
		arr[i] = i;
	}

	int idx1, idx2, temp;
	for (int i = 0; i < 10; i++)
	{
		idx1 = rand() % 4;
		idx2 = rand() % 4;

		temp = arr[idx1];
		arr[idx1] = arr[idx2];
		arr[idx2] = temp;
	}

	for (int i = 0; i < 3; ++i)
	{
		enemies.emplace_back(arr[i]);
	}
}
