#include "GameScene.h"
#include "Mci.h"


void GameScene(Scene& _eCurScene, Player& player, ScoreManager& scoreManager, EnemyManager& enemyManager)
{
	GameSceneRender();
	GameSceneUpdate(_eCurScene,player, scoreManager, enemyManager);
}

void GameSceneInit(ScoreManager& scoreManager, Player& player, EnemyManager& enemyManager)
{
	PlaySoundID(SOUNDID::GameBGM, true);
	system("cls");
	scoreManager.Initialize();
	enemyManager.Initialize();
	scoreManager.ScoreRender();
	player.ResetPlayer();

	COORD hpUIpos{ 0, 10 };
	player.RenderHpInit(hpUIpos);
}

void GameSceneUpdate(Scene& _eCurScene, Player& player, ScoreManager& scoreManager, EnemyManager& enemyManager)
{
	enemyManager.EnemyUpdate(scoreManager, player);
	player.PlayerControl(player,_eCurScene);

	COORD hpUIpos{ 0, 10 };
	player.RenderHp(hpUIpos);
}

void GameSceneRender()
{
	COORD centerPos = GetConsoleResolution();
	centerPos.X /= 2;
	centerPos.Y /= 2;

	Shield shield(centerPos);
}

