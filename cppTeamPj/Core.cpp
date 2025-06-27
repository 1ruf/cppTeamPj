#include "Core.h"

void Core::Run()
{
	Scene currentScene = Scene::MENU;
	Scene beforeScene = Scene::FAIL;
	Player player("●",&currentScene);
	ScoreManager scoreManager;
	Init();
	while (currentScene != Scene::EXIT)
	{
		Update(currentScene,beforeScene,player, scoreManager);
		Render(currentScene);
	}
}

void Core::Init()
{
	SetConsoleSettings(900, 900, false, L"HIDER");
	SetCursorVisual(false, 20);
	srand((unsigned int)time(nullptr));
}

void Core::Update(Scene& curScene, Scene& befScene, Player& player, ScoreManager& scoreManager)
{
	switch (curScene)
	{
	case Scene::MENU:
		if (befScene != curScene) InitTitle();
		OpenTitleScene(curScene);
		break;
	case Scene::GAME:
		OpenGameScene(curScene, player, scoreManager);
		break;
	case Scene::CREDIT:
		OpenCreditScene(curScene);
		break;
	case Scene::INFO:
		if (befScene != curScene) InitInfo();
		OpenInfoScene(curScene);
		break;
	case Scene::GAMEOVER:
		Gotoxy(0, 0);
		if (befScene != curScene) InitGameOver();
		OpenGameOverScene(curScene,scoreManager);
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
	befScene = curScene;
}

void Core::Render(Scene& curScene)
{
	
}
