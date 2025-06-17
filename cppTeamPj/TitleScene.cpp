#include "TitleScene.h"
#include "KeyContoller.h"

void TitleScene(Scene& _eCurScene,Menu& _eCurMenu)
{
	TitleSceneRender();
	TitleSceneUpdate(_eCurScene,_eCurMenu);
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
	wcout << L"	  ▄▄▄█  |    ▄███▄▄▄▄███▄▄ ███▌ ███    ███  ▄███▄▄▄      ▄███▄▄▄▄██▀   |   █▄▄▄" << endl;
	wcout << L"	     █  |   ▀▀███▀▀▀▀███▀  ███▌ ███    ███ ▀▀███▀▀▀     ▀▀███▀▀▀▀▀     |   █" << endl;
	wcout << L"	        |     ███    ███   ███  ███    ███   ███    █▄  ▀███████████   |" << endl;
	wcout << L"	        |     ███    ███   ███  ███   ▄███   ███    ███   ███    ███   |" << endl;
	wcout << L"	        |     ███    █▀    █▀   ████████▀    ██████████   ███    ███   |" << endl;
	wcout << L"	        |                                                 ███    ███   |" << endl;
	COORD menuPos{ ((consoleSize.X) / 2) - 5, 2 * (consoleSize.Y) / 3 };

	
	int curmode = _setmode(_fileno(stdout), prevmode);//현재 메뉴에 따라서

	Gotoxy(menuPos.X - 23, menuPos.Y);
	cout << "게임 시작" << endl;
	Gotoxy(menuPos.X - 7, menuPos.Y);
	cout << "게임 정보" << endl;
	Gotoxy(menuPos.X + 7, menuPos.Y);
	cout << "  크레딧" << endl;
	Gotoxy(menuPos.X + 23, menuPos.Y);
	cout << "게임 종료" << endl;
}

void TitleSceneUpdate(Scene& _eCurScene,Menu& _eCurMenu)
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

void RenderCredit()
{
}

void RenderInfo()
{
}

void RenderBox(int curIndex)
{
	COORD consoleSize = GetConsoleResolution();
	COORD menuPos { ((consoleSize.X) / 2) - 5, 2 * (consoleSize.Y) / 3 };

	SelectBar selectBar;
	COORD drawPos{ 0,0 };
	switch (curIndex)
	{
	case 0:
		drawPos.X = menuPos.X - 20;
		drawPos.Y = menuPos.Y;
		break;
	case 1:
		drawPos.X = menuPos.X - 4;
		drawPos.Y = menuPos.Y;
		break;
	case 2:
		drawPos.X = menuPos.X + 10;
		drawPos.Y = menuPos.Y;
		break;
	case 3:
		drawPos.X = menuPos.X + 26;
		drawPos.Y = menuPos.Y;
		break;
	default:
		break;
	}
	selectBar.Draw(drawPos);
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
	RenderBox(selectIndex);
	return Menu();
}
