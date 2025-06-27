#include "CreditScene.h"

void CreditScene(Scene& _eCurScene)
{
	CreditSceneRender();
	CreditSceneUpdate(_eCurScene);
}

void CreditSceneInit()
{
}

void CreditSceneUpdate(Scene& _eCurScene)
{
	CreditSceneExit(_eCurScene);
}

void CreditSceneRender()
{
	COORD consoleSize = GetConsoleResolution();

	Gotoxy(3, 1);
	cout << "< 종료:ESC >" << endl;
	Gotoxy(consoleSize.X / 2 - 8, consoleSize.Y / 2 - 10);
	cout << "크레딧 페이지입니다." << endl;
	cout << "이 게임은 C++로 제작된 콘솔 게임입니다." << endl;
	cout << "개발자: Mr.ChanMinLee | 고한1결" << endl;
	cout << "감사합니다!" << endl;
}

void CreditSceneExit(Scene& _eCurScene)
{
	Key eKey = KeyController();
	if (eKey == Key::ESC)
	{
		_eCurScene = Scene::MENU;
	}
}
