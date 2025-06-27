#include "GameScene.h"


void GameScene(Scene& _eCurScene, Player& player, ScoreManager& scoreManager, EnemyManager& enemyManager)
{
	GameSceneRender();
	GameSceneUpdate(_eCurScene,player, scoreManager, enemyManager);
}

void GameSceneInit(ScoreManager& scoreManager, Player& player, EnemyManager& enemyManager)
{
	scoreManager.Initialize();
	enemyManager.Initialize();
	scoreManager.ScoreRender();
	player.ResetPlayer();
}

void GameSceneUpdate(Scene& _eCurScene, Player& player, ScoreManager& scoreManager, EnemyManager& enemyManager)
{
	enemyManager.EnemyUpdate(scoreManager, player);
	player.PlayerControl(player,_eCurScene);
	player.GetPosition();//��ġ �������°��� @������
}

void GameSceneRender()
{
	COORD centerPos = GetConsoleResolution();
	centerPos.X /= 2;
	centerPos.Y /= 2;

	Shield shield(centerPos);
}

