#include "Core.h"
#include "PlayerContoller.h"
#include "Scenes.h"
#include "Console.h"
#include "Player.h"

void Core::Run()
{
	Scene currentScene = Scene::MENU;
	Menu currentMenu = Menu::START;
	Player player("¡Ü");
	Init();
	while (true)
	{
		Update(currentMenu,currentScene,player);
		Render(currentScene);
	}
}

void Core::Init()
{
	SetConsoleSettings(800, 600, false, L"HIDER");
}

void Core::Update(Menu& curMenu,Scene& curScene, Player& player)
{
	while (true)
	{
		switch (curScene)
		{
		case Scene::MENU:
			OpenTitleScene(curScene,curMenu);
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
