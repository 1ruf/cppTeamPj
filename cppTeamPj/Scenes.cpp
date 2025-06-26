#include "Scenes.h"
#include "GameScene.h"
#include "TitleScene.h"
#include "InfoScene.h"
#include "CreditScene.h"
#include "Player.h"

void OpenGameScene(Scene& _eCurScene, Player& player, ScoreManager& scoreManager)
{
	GameScene(_eCurScene, player,scoreManager);
}

void InitGame()
{
	GameSceneInit();
}

void OpenTitleScene(Scene& _eCurScene)
{
	TitleScene(_eCurScene);
}
void InitTitle()
{
	TitleSceneInit();
}
void OpenInfoScene(Scene& _eCurScene)
{
	InfoScene(_eCurScene);
}
void InitInfo()
{
	InfoSceneInit();
}
void OpenCreditScene(Scene& _eCurScene)
{
	CreditScene(_eCurScene);
}

void InitCredit()
{
	InfoSceneInit();
}
