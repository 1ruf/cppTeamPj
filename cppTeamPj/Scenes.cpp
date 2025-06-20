#include "Scenes.h"
#include "GameScene.h"
#include "TitleScene.h"
#include "InfoScene.h"
#include "CreditScene.h"
#include "Player.h"

void OpenGameScene(Scene& _eCurScene, Player& player)
{
	GameScene(_eCurScene, player);
}

void OpenTitleScene(Scene& _eCurScene)
{
	TitleScene(_eCurScene);
}
void OpenInfoScene(Scene& _eCurScene)
{
	InfoScene(_eCurScene);
}
void OpenCreditScene(Scene& _eCurScene)
{
	CreditScene(_eCurScene);
}