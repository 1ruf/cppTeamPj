#include "GameScene.h"
#include <iostream>

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


