#include "GameScene.h"

void GameScene(Scene& _eCurScene)
{
	GameSceneRender();
	GameSceneUpdate(_eCurScene);
}

void GameSceneUpdate(Scene& _eCurScene)
{

}

void GameSceneRender()
{
	system("cls");
	std::cout << "¤¤¤¤¤¤";
}


