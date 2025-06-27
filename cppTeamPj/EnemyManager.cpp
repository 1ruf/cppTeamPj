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
		for (auto iterator = playerEnemies.begin(); iterator != playerEnemies.end(); )
		{
			if (iterator->CheckShield())
			{
				iterator = playerEnemies.erase(iterator);
				enemyCount++;
				if (enemyCount >= 3)
				{
					scoreManager.ScoreUp(1);
					DownSpawnTime(0.0051f);
					DownMoveTime(0.00012f);
				}
			}
			else if (iterator->CheckPlayer(player.GetPosition()))
			{
				player.Hit();
				iterator = playerEnemies.erase(iterator);
			}
			else
			{
				iterator->Move();
				++iterator;
			}
		}

		for (auto iterator = shieldEnemies.begin(); iterator != shieldEnemies.end();)
		{
			if (iterator->CheckShield())
			{
				player.Hit();
				iterator = shieldEnemies.erase(iterator);
			}
			else if (iterator->CheckPlayer(player.GetPosition()))
			{
				iterator = shieldEnemies.erase(iterator);
				scoreManager.ScoreUp(1);
				DownSpawnTime(0.0051f);
				DownMoveTime(0.00012f);
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
	int randNum = rand() % 10;

	if (randNum >= 2)
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
			playerEnemies.emplace_back(arr[i]);
		}
	}

	else
	{
		int randValue = rand() % 4;
		shieldEnemies.emplace_back(randValue);
	}
}

void EnemyManager::DownSpawnTime(float downTime)
{
	spawnTime -= downTime;
}

void EnemyManager::DownMoveTime(float downTime)
{
	moveTime -= downTime;
}
