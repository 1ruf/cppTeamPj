#include "GameScene.h"

EnemyManager enemyManager;

void GameScene(Scene& _eCurScene)
{
	GameSceneRender();
	GameSceneUpdate(_eCurScene);
}

void GameSceneUpdate(Scene& _eCurScene)
{
	enemyManager.EnemyUpdate();
}

void GameSceneRender()
{
	COORD centerPos = GetConsoleResolution();
	centerPos.X /= 2;
	centerPos.Y /= 2;

	Sheild shield(centerPos);
}


