#include "Core.h"
#include "PlayerContoller.h"
#include "Scenes.h"

void Core::Run()
{
	Scene currentScene = Scene::MENU;
	while (true)
	{
		switch (currentScene)
		{
		case Scene::MENU:
			OpenTitleScene(currentScene);
			break;
		case Scene::GAME:
			OpenGameScene(currentScene);
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

void Core::Update()
{
	//HandleInput(_pos, _menu);
}

void Core::Render()
{
}
