#include "Core.h"


void Core::Run()
{
	Scene currentScene = Scene::MENU;
	while (true)
	{
		switch (currentScene)
		{
		case Scene::MENU:
			break;
		case Scene::GAME:
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
}

void Core::Render()
{
}
