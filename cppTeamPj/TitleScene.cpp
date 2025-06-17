#include "TitleScene.h"
#include "Console.h"
#include "KeyContoller.h"
#include <fcntl.h>
#include <io.h>

void TitleScene(Menu& _eCurMenu)
{
	TitleSceneRender();
	TitleSceneUpdate(_eCurMenu);
}

void TitleSceneRender()
{
	COORD consoleSize = GetConsoleResolution();

	//Gotoxy(consoleSize.X / 2 - 8, consoleSize.Y / 2 - 10);
	Gotoxy(0, consoleSize.Y / 2 - 10);

	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);

	wcout << L"	        |      ▄█    █▄     ▄█  ████████▄     ▄████████    ▄████████   |" << endl;
	wcout << L"	        |     ███    ███   ███  ███   ▀███   ███    ███   ███    ███   |" << endl;
	wcout << L"	        |     ███    ███   ███▌ ███    ███   ███    █▀    ███    ███   |" << endl;
	wcout << L"	  ▄▄▄   |    ▄███▄▄▄▄███▄▄ ███▌ ███    ███  ▄███▄▄▄      ▄███▄▄▄▄██▀   |   ▄▄▄" << endl;
	wcout << L"	        |   ▀▀███▀▀▀▀███▀  ███▌ ███    ███ ▀▀███▀▀▀     ▀▀███▀▀▀▀▀     |" << endl;
	wcout << L"	        |     ███    ███   ███  ███    ███   ███    █▄  ▀███████████   |" << endl;
	wcout << L"	        |     ███    ███   ███  ███   ▄███   ███    ███   ███    ███   |" << endl;
	wcout << L"	        |     ███    █▀    █▀   ████████▀    ██████████   ███    ███   |" << endl;
	wcout << L"	        |                                                 ███    ███   |" << endl;
	COORD menuPos{ (consoleSize.X) / 2, 2 * (consoleSize.Y) / 3 };

	Gotoxy(menuPos.X - 21, menuPos.Y - 1);
	wcout << L"┏";
	Gotoxy(menuPos.X - 8, menuPos.Y - 1);
	wcout << L"┓" << endl;
	Gotoxy(menuPos.X - 21, menuPos.Y + 1);
	wcout << L"┗";
	Gotoxy(menuPos.X - 8, menuPos.Y + 1);
	wcout << L"┛" << endl;
	int curmode = _setmode(_fileno(stdout), prevmode);

	Gotoxy(menuPos.X - 18, menuPos.Y);
	cout << "게임 시작" << endl;
	Gotoxy(menuPos.X - 3, menuPos.Y);
	cout << "게임 정보" << endl;
	Gotoxy(menuPos.X + 12, menuPos.Y);
	cout << "게임 종료" << endl;
}

void TitleSceneUpdate(Menu& _eCurMenu)
{
	Menu eMenu = TitleSceneInput();
	switch (eMenu)
	{
	case Menu::START:
		break;
	case Menu::INFO:
		break;
	case Menu::CREDITS:
		break;
	case Menu::EXIT:
		break;
	case Menu::FAIL:
		break;
	default:
		break;
	}
}

Menu TitleSceneInput()
{
	int selectIndex = 0;
	Key eKey = KeyController();
	switch (eKey)
	{
	case Key::A:
		if (selectIndex == 0)
		{
			selectIndex = 3;
		}
		else
			selectIndex--;
		Sleep(100);
		break;
	case Key::D:
		if (selectIndex == 3)
			selectIndex = 0;
		else
			selectIndex++;
		Sleep(100);
		break;
	case Key::SPACE:
		if (selectIndex == 0) Menu::START;
		else if (selectIndex == 1) Menu::INFO;
		else if (selectIndex == 2) Menu::EXIT;
		else if (selectIndex == 3) Menu::CREDITS;
		else return Menu::FAIL;
		break;
	}
	return Menu();
}
