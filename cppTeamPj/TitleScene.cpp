#include "TitleScene.h"

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
	Gotoxy(menuPos.X + 9, menuPos.Y);
	cout << "크레딧" << endl;
	Gotoxy(menuPos.X + 23, menuPos.Y);
	cout << "게임 종료" << endl;
}

void TitleSceneUpdate(Scene& _eCurScene,Menu& _eCurMenu)
{
	Menu eMenu = TitleSceneInput();
	switch (eMenu)
	{
	case Menu::START:
		_eCurScene = Scene::GAME;
		break;
	case Menu::INFO:
		_eCurScene = Scene::INFO;
		break;
	case Menu::CREDITS:
		_eCurScene = Scene::CREDIT;
		break;
	case Menu::EXIT:
		_eCurScene = Scene::EXIT;
		break;
	case Menu::FAIL:
		_eCurScene = Scene::MENU;
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

void RenderBox()
{
	COORD consoleSize = GetConsoleResolution();
	COORD menuPos { ((consoleSize.X) / 2) - 5, 2 * (consoleSize.Y) / 3 };

	SelectBar selectBar;
	COORD drawPos{ 0,0 };

	int curIndex = selectBar.GetIndex();
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
	SelectBar sBar;
	Key eKey = KeyController();
	int selectIndex = sBar.GetIndex();
	cout << selectIndex;
	switch (eKey)
	{
	case Key::A:
		if (selectIndex == 0)
		{
			selectIndex = 3;
		}
		else
			selectIndex--;
		system("cls");
		//Sleep(150);
		break;
	case Key::D:
		if (selectIndex == 3)
			selectIndex = 0;
		else
			selectIndex++;
		system("cls");
		//Sleep(150);
		break;
	case Key::SPACE:
		system("cls");
		if (selectIndex == 0)return Menu::START;
		else if (selectIndex == 1)return Menu::INFO;
		else if (selectIndex == 2)return Menu::EXIT;
		else if (selectIndex == 3)return Menu::CREDITS;
		break;
	}
	sBar.SetIndex(selectIndex);
	RenderBox();
	return Menu::FAIL;
}

void SelectBar::SetIndex(int index)
{
	selectIndex = index;
}

int SelectBar::GetIndex()
{
	return selectIndex;
}
