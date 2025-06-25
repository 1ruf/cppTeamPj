#include "GameScene.h"
#include "ScoreManager.h"

EnemyManager enemyManager;

void GameScene(Scene& _eCurScene, Player& player)
{
	ScoreManager scoreManager;
	GameSceneRender();
	GameSceneUpdate(_eCurScene,player, scoreManager);
}

void GameSceneInit()
{
}

void GameSceneUpdate(Scene& _eCurScene, Player& player, ScoreManager& scoreManager)
{
	enemyManager.EnemyUpdate(scoreManager, player);
	player.PlayerControl(player,_eCurScene);
	player.GetPosition();//위치 가져오는거임 @이찬민
}

void GameSceneRender()
{
	COORD centerPos = GetConsoleResolution();
	centerPos.X /= 2;
	centerPos.Y /= 2;

	Shield shield(centerPos);
}

