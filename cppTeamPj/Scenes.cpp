#include "Scenes.h"
#include "GameScene.h"
#include "TitleScene.h"
#include "InfoScene.h"
#include "Player.h"

void OpenGameScene(Scene& _eCurScene, Player& player)
{
	GameScene(_eCurScene, player);
}

void OpenTitleScene(Scene& _eCurScene,Menu& _eCurMenu)
{
	TitleScene(_eCurScene,_eCurMenu);
}
void OpenInfoScene(Scene& _eCurScene)
{
	InfoScene(_eCurScene);
}