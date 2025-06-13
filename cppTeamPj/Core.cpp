#include "Core.h"
#include "PlayerContoller.h"
#include "Scenes.h"
#include "Console.h"

void Core::Run()
{
	Scene currentScene = Scene::MENU;
	Init();
	while (true)
	{
		Update(currentScene);
		Render(currentScene);
	}
}

void Core::Init()
{
	SetConsoleSettings(800, 600, false, L"HIDER");
}

void Core::Update(Scene& curScene)
{
	while (true)
	{
		switch (curScene)
		{
		case Scene::MENU:
			OpenTitleScene(curScene);
			break;
		case Scene::GAME:
			OpenGameScene(curScene);
			break;
		case Scene::PAUSE:
			break;
		case Scene::INFO:
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
