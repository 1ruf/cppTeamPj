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
	cout << "< ����:ESC >" << endl;
	Gotoxy(consoleSize.X / 2 - 8, consoleSize.Y / 2 - 10);
	cout << "ũ���� �������Դϴ�." << endl;
	cout << "�� ������ C++�� ���۵� �ܼ� �����Դϴ�." << endl;
	cout << "������: Mr.ChanMinLee | ����1��" << endl;
	cout << "�����մϴ�!" << endl;
}

void CreditSceneExit(Scene& _eCurScene)
{
	Key eKey = KeyController();
	if (eKey == Key::ESC)
	{
		_eCurScene = Scene::MENU;
	}
}
