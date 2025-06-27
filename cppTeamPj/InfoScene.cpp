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
	cout << "< ����:ESC >" << endl;
	Gotoxy(consoleSize.X / 2 - 8, consoleSize.Y / 2 - 10);
	cout << "���� ���� �������Դϴ�." << endl;
	cout << "�� ������ C++�� ���۵� �ܼ� �����Դϴ�." << endl;
	cout << "������ ��ǥ�� ���� ���ϸ鼭 �����ϴ� ���Դϴ�." << endl;
}

void InfoSceneExit(Scene& _eCurScene)
{
	Key eKey = KeyController();
	if (eKey == Key::ESC)
	{
		_eCurScene = Scene::MENU;
	}
}
