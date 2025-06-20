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
	PlayerControl(player,_eCurScene);
}

void GameSceneRender()
{
	COORD centerPos = GetConsoleResolution();
	centerPos.X /= 2;
	centerPos.Y /= 2;

	Sheild shield(centerPos);
}

void PlayerControl(Player& player,Scene& _curScene)
{
	HandleInput(player, _curScene);
	PlayerRender(player);
}

void PlayerRender(Player plr)
{
	COORD centerPos = GetConsoleResolution();
	centerPos.X /= 2;
	centerPos.Y /= 2;

	CUR_MOVE curMove = plr.GetDirection();
	COORD renderPos = { centerPos.X, centerPos.Y };

	switch (curMove)
	{
	case CUR_MOVE::UP:
		renderPos.Y -= 2;
		break;
	case CUR_MOVE::DOWN:
		renderPos.Y += 2;
		break;
	case CUR_MOVE::LEFT:
		renderPos.X -= 4;
		break;
	case CUR_MOVE::RIGHT:
		renderPos.X += 4;
		break;
	default:
		break;
	}
	Gotoxy(renderPos.X, renderPos.Y);
	std::cout << plr.objectVisual;
}


