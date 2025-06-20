#include "Core.h"

void Core::Run()
{
	Scene currentScene = Scene::MENU;
	Player player("¡Ü");
	Init();
	while (currentScene != Scene::EXIT)
	{
		Update(currentScene,player);
		Render(currentScene);
	}
}

void Core::Init()
{
	SetConsoleSettings(800, 600, false, L"HIDER");
	srand((unsigned int)time(nullptr));
}

void Core::Update(Scene& curScene, Player& player)
{
	while (true)
	{
		switch (curScene)
		{
		case Scene::MENU:
			OpenTitleScene(curScene);
			break;
		case Scene::GAME:
			OpenGameScene(curScene,player);
			break;
		case Scene::CREDIT:
			OpenCreditScene(curScene);
			break;
		case Scene::INFO:
			OpenInfoScene(curScene);
			break;
		case Scene::PAUSE:
			break;
		case Scene::EXIT:
			break;
		case Scene::FAIL:
			break;
		default:
			break;
		}
	}
}

void Core::Render(Scene& curScene)
{
	
}
