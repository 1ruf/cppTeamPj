#include "Core.h"

void Core::Run()
{
	Scene currentScene = Scene::MENU;
	Player player("●");
	Init();
	while (currentScene != Scene::EXIT)
	{
		Update(currentScene,player);
		Render(currentScene);
	}
}

void Core::Init()
{
	SetConsoleSettings(800, 800, false, L"HIDER");
	srand((unsigned int)time(nullptr));
}

void Core::Update(Scene& curScene, Player& player)
{
	switch (curScene)
	{
	case Scene::MENU:
		OpenTitleScene(curScene);
		break;
	case Scene::GAME:
		OpenGameScene(curScene, player);
		break;
	case Scene::CREDIT:
		OpenCreditScene(curScene);
		break;
	case Scene::INFO:
		OpenInfoScene(curScene);
		break;
	case Scene::GAMEOVER:
		Gotoxy(0, 0);
		cout << "GAME OVER";
		break;
	case Scene::PAUSE:
		break;
	case Scene::EXIT:
		std::cout << "게임 종료";
		break;
	case Scene::FAIL:
		break;
	default:
		break;
	}
}

void Core::Render(Scene& curScene)
{
	
}
