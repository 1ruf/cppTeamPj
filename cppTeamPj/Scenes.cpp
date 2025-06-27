#include "Scenes.h"
#include "GameScene.h"
#include "TitleScene.h"
#include "GameOverScene.h"
#include "InfoScene.h"
#include "CreditScene.h"
#include "Player.h"
#include "GameOverManager.h"

void OpenGameScene(Scene& _eCurScene, Player& player, ScoreManager& scoreManager)
{
	GameScene(_eCurScene, player,scoreManager);
}

void InitGame(ScoreManager& scoreManager,Player& player)
{
	GameSceneInit(scoreManager,player);
}

void OpenGameOverScene(Scene& _eCurScene, ScoreManager scoreManager,GameOverManager& gameoverManager)
{
	GameOverScene(_eCurScene,scoreManager, gameoverManager);
}

void InitGameOver()
{
	system("cls");
	GameOverInit();
}

void OpenTitleScene(Scene& _eCurScene)
{
	TitleScene(_eCurScene);
}
void InitTitle()
{
	system("cls");
	TitleSceneInit();
}
void OpenInfoScene(Scene& _eCurScene)
{
	InfoScene(_eCurScene);
}
void InitInfo()
{
	system("cls");
	InfoSceneInit();
}
void OpenCreditScene(Scene& _eCurScene)
{
	CreditScene(_eCurScene);
}

void InitCredit()
{
	system("cls");
	InfoSceneInit();
}
