#include "GameScene.h"

EnemyManager enemyManager;

void GameScene(Scene& _eCurScene, Player& player, ScoreManager& scoreManager)
{
	GameSceneRender();
	GameSceneUpdate(_eCurScene,player, scoreManager);
}

void GameSceneInit(ScoreManager& scoreManager)
{
	scoreManager.ScoreRender();
}

void GameSceneUpdate(Scene& _eCurScene, Player& player, ScoreManager& scoreManager)
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

