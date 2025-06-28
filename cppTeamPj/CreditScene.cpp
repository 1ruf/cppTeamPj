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
	Gotoxy(0, consoleSize.Y / 2 - 15);
	cout << "��ȹ�� : ���Ѱ�, ������" << endl;
	cout << "������ : ���Ѱ�, ������" << endl;
	cout << "������ : ���Ѱ�, ������\n\n\n" << endl;
	cout << "???:���Ѱ��̶� �������� �ٸ������ ���� ������ ������ �� ����?" << endl;
	Gotoxy(consoleSize.X / 2, consoleSize.Y / 2 + 20);
	cout << "\n�÷��� ���ּż� �����մϴ�!" << endl;
}

void CreditSceneExit(Scene& _eCurScene)
{
	Key eKey = KeyController();
	if (eKey == Key::ESC)
	{
		_eCurScene = Scene::MENU;
	}
}
