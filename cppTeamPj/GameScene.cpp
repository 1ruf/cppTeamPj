#include "GameScene.h"

EnemyManager enemyManager;

void GameScene(Scene& _eCurScene, Player& player)
{
	GameSceneRender();
	GameSceneUpdate(_eCurScene,player);
}

void GameSceneUpdate(Scene& _eCurScene, Player& player)
{
	enemyManager.EnemyUpdate();
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

