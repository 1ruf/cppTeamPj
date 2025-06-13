#include "Scenes.h"
#include "GameScene.h"
#include "TitleScene.h"

void OpenGameScene(Scene& _eCurScene)
{
	GameScene(_eCurScene);
}

void OpenTitleScene(Scene& _eCurScene)
{
	TitleScene(_eCurScene);
}
