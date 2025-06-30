#include "EnemyManager.h"
#include "Mci.h"


void EnemyManager::LevelUp(ScoreManager& scoreManager)
{
	scoreManager.ScoreUp(1);
	if (scoreManager.GetScore() > DifficultyLevelPointHigh)
	{
		DownSpawnTime(spawnDownLow);
		DownMoveTime(moveDownLow);
	}
	else if (scoreManager.GetScore() > DifficultyLevelPointLow)
	{
		DownSpawnTime(spawnDownMid);
		DownMoveTime(moveDownMid);
	}
	else
	{
		DownSpawnTime(spawnDownHigh);
		DownMoveTime(moveDownHigh);
	}
}

void EnemyManager::EnemyUpdate(ScoreManager& scoreManager, Player& player)
{
	auto currentTime = std::chrono::high_resolution_clock::now();
	float deltaTime = std::chrono::duration<float>(currentTime - lastUpdateTime).count();
	lastUpdateTime = currentTime;

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
					PlaySoundID(SOUNDID::ShieldHit, false);
					LevelUp(scoreManager);
				}
			}
			else if (iterator->CheckPlayer(player.GetPosition()))
			{
				PlaySoundID(SOUNDID::PlayerDamage, false);
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
				PlaySoundID(SOUNDID::ShieldDamage, false);
				player.Hit();
				iterator = shieldEnemies.erase(iterator);
			}
			else if (iterator->CheckPlayer(player.GetPosition()))
			{
				PlaySoundID(SOUNDID::PlayerHit, false);
				iterator = shieldEnemies.erase(iterator);
				LevelUp(scoreManager);
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

	if (randNum >= 3)
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


void EnemyManager::Initialize()
{
	lastUpdateTime = std::chrono::high_resolution_clock::now();
	spawnTimer = moveTimer = 0.0f;
	spawnTime = defaultSpawnTime;
	moveTime = defaultMoveTime;
	playerEnemies.clear();
	shieldEnemies.clear();
}

