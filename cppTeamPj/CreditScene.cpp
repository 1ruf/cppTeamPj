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
	Gotoxy(0, consoleSize.Y / 2 - 15);
	cout << "기획자 : 고한결, 이찬민" << endl;
	cout << "제작자 : 고한결, 이찬민" << endl;
	cout << "디자인 : 고한결, 이찬민\n\n\n" << endl;
	cout << "???:고한결이랑 이찬민이 다만들었네 ㄷㄷ 나머지 팀원들 다 뭐함?" << endl;
	Gotoxy(consoleSize.X / 2, consoleSize.Y / 2 + 20);
	cout << "\n플레이 해주셔서 감사합니다!" << endl;
}

void CreditSceneExit(Scene& _eCurScene)
{
	Key eKey = KeyController();
	if (eKey == Key::ESC)
	{
		_eCurScene = Scene::MENU;
	}
}
