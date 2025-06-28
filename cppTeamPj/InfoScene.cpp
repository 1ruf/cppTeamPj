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
	cout << "< ����:ESC >\n\n";
	cout << "HIDER ���� ���� �������Դϴ�." << endl;
	Gotoxy(0, consoleSize.Y / 2 - 20);
	cout << "�� ������ ���� ���� ���� �ڷ� ���� �����Դϴ�.\n";
	cout << "-����Ű-\n[\n- ��ȣ�ۿ� : SPACE\n- ������ : ESC\n- �̵�(��,��,��,��) : W,S,A,D\n]\n\n";
	cout << "�Ͼ�ȭ��ǥ(��) : �Ͼ�� ���� �÷��̾ ���ؾ� �մϴ�.\n\t�� ���� �÷��̾ ������ �ȵ˴ϴ�.\n";
	cout << "����ȭ��ǥ(��) : ";
	SetColor(COLOR::RED);
	cout << "������"; 
	SetColor();
	cout << " ���� �÷��̾ �¾ƾ� �մϴ�.\n\t�� ���� ���а� ������ �ȵ˴ϴ�.\n\n";
	cout << "������ ���̵��� ������ ��ʿ��� �����մϴ�!";


	SetColor();
}

void InfoSceneExit(Scene& _eCurScene)
{
	Key eKey = KeyController();
	if (eKey == Key::ESC)
	{
		_eCurScene = Scene::MENU;
	}
}
