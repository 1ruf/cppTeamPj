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
		int enemyCount = 0;
		for (auto iterator = enemies.begin(); iterator != enemies.end(); )
		{
			if (iterator->CheckShield())
			{
				iterator = enemies.erase(iterator);
				enemyCount++;
				if (enemyCount >= 3)
				{
					scoreManager.ScoreUp(1);
				}
			}
			else if (iterator->CheckPlayer(player.GetPosition()))
			{
				player.Hit();
				iterator = enemies.erase(iterator);
			}
			else
			{
				iterator->Move();
				++iterator;
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
