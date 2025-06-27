#include "Core.h"
#include "GameOverManager.h"

void Core::Run()
{
	Scene currentScene = Scene::MENU;
	Scene beforeScene = Scene::FAIL;
	Player player("●",&currentScene);
	ScoreManager scoreManager;
	GameOverManager gameoverManager;
	EnemyManager enemyManager;

	Init();
	while (currentScene != Scene::EXIT)
	{
		Update(currentScene,beforeScene,player, scoreManager, gameoverManager, enemyManager);
		Render(currentScene);
	}
}

void Core::Init()
{
	SetConsoleSettings(900, 900, false, L"HIDER");
	SetCursorVisual(false, 20);
	srand((unsigned int)time(nullptr));

	COORD res = GetConsoleResolution();
	std::string target = "Hello, World!";
	std::string output = "";
	for (int i = 0; i < target.size(); ++i)
	{
		Gotoxy(res.X / 2 - i / 2, res.Y / 2);
		output += target[i];
		cout << output;
		Sleep(20);
	}
	Sleep(500);
	system("cls");
}

void Core::Update(Scene& curScene, Scene& befScene, Player& player, ScoreManager& scoreManager, GameOverManager& gameoverManager, EnemyManager& enemyManager)
{
	switch (curScene)
	{
	case Scene::MENU:
		if (CheckSceneInit(befScene,curScene) == false) InitTitle();
		OpenTitleScene(curScene);
		break;
	case Scene::GAME:
		if (CheckSceneInit(befScene, curScene) == false) InitGame(scoreManager, player, enemyManager);
		OpenGameScene(curScene, player, scoreManager, enemyManager);
		break;
	case Scene::CREDIT:
		if (CheckSceneInit(befScene, curScene) == false) InitCredit();
		OpenCreditScene(curScene);
		break;
	case Scene::INFO:
		if (CheckSceneInit(befScene, curScene) == false) InitInfo();
		OpenInfoScene(curScene);
		break;
	case Scene::GAMEOVER:
		if (CheckSceneInit(befScene, curScene) == false) InitGameOver();
		OpenGameOverScene(curScene,scoreManager, gameoverManager);
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

bool CheckSceneInit(Scene& befScene, Scene& curScene)
{
	bool result = befScene == curScene;
	if (result == false) befScene = curScene;
	return result;
}
