#include "InfoScene.h"

void InfoScene(Scene& _eCurScene)
{
	InfoSceneRender();
	InfoSceneUpdate(_eCurScene);
}

void InfoSceneInit()
{
	system("cls");
}

void InfoSceneUpdate(Scene& _eCurScene)
{
	InfoSceneExit(_eCurScene);
}

void InfoSceneRender()
{
	COORD consoleSize = GetConsoleResolution();

	Gotoxy(3, 1);
	cout << "< 종료:ESC >" << endl;
	Gotoxy(consoleSize.X / 2 - 8, consoleSize.Y / 2 - 10);
	cout << "게임 정보 페이지입니다." << endl;
	cout << "이 게임은 C++로 제작된 콘솔 게임입니다." << endl;
	cout << "게임의 목표는 적을 피하면서 생존하는 것입니다." << endl;
}

void InfoSceneExit(Scene& _eCurScene)
{
	Key eKey = KeyController();
	if (eKey == Key::ESC)
	{
		_eCurScene = Scene::MENU;
	}
}
