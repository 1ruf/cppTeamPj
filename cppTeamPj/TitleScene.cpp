#include "TitleScene.h"

void TitleScene(Scene& _eCurScene)
{
	TitleSceneRender();
	TitleSceneUpdate(_eCurScene);
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

void TitleSceneUpdate(Scene& _eCurScene)
{
	_eCurScene = TitleSceneInput();
}

void RenderBox(int curIndex)
{
	COORD consoleSize = GetConsoleResolution();
	COORD menuPos{ ((consoleSize.X) / 2) - 5, 2 * (consoleSize.Y) / 3 };

	SelectBar selectBar; //이거 나중에 진짜 map으로 하던 따로 빼던 바꿔야함. 일단 플레이어 만들러감

	COORD pos0 = { menuPos.X - 20, menuPos.Y };
	COORD pos1 = { menuPos.X - 4,  menuPos.Y };
	COORD pos2 = { menuPos.X + 10, menuPos.Y };
	COORD pos3 = { menuPos.X + 26, menuPos.Y };

	selectBar.Erase(pos0);
	selectBar.Erase(pos1);
	selectBar.Erase(pos2);
	selectBar.Erase(pos3);

	switch (curIndex)
	{
	case 0:
		selectBar.Draw(pos0);
		break;
	case 1:
		selectBar.Draw(pos1);
		break;
	case 2:
		selectBar.Draw(pos2);
		break;
	case 3:
		selectBar.Draw(pos3);
		break;
	default:
		break;
	}
}

int selectIndex = 0;
Scene TitleSceneInput()
{
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
		//system("cls");
		Sleep(50);
		break;
	case Key::D:
		if (selectIndex == 3)
			selectIndex = 0;
		else
			selectIndex++;
		//system("cls");
		Sleep(50);
		break;
	case Key::SPACE:
		system("cls");
		if (selectIndex == 0)
		{
			CrossAnimation(GetConsoleResolution(),1);
			system("cls");
			return Scene::GAME;
		}
		else if (selectIndex == 1)return Scene::INFO;
		else if (selectIndex == 2)return Scene::CREDIT;
		else if (selectIndex == 3)return Scene::EXIT;
		break;
	}
	RenderBox(selectIndex);
	return Scene::MENU;
}

void SelectBar::Draw(COORD pos, COLOR textColor, COLOR bgColor)
{
	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);

	int xVal = _width % 2 == 0 ? _width / 2 : _width / 2 - 1;
	int yVal = _height % 2 == 0 ? _height / 2 : _height / 2 - 1;
	SetColor(textColor, bgColor);

	Gotoxy(pos.X - xVal, pos.Y - yVal);
	wcout << L"┏";
	Gotoxy(pos.X + xVal, pos.Y - yVal);
	wcout << L" ┓" << endl;
	Gotoxy(pos.X - xVal, pos.Y + yVal);
	wcout << L"┗";
	Gotoxy(pos.X + xVal, pos.Y + yVal);
	wcout << L" ┛" << endl;

	SetColor();
	int curmode = _setmode(_fileno(stdout), prevmode);
}
void CrossAnimation(COORD _resolution, int _delayTime)
{
	for (int i = 0; i < _resolution.X / 2; ++i)
	{
		for (int j = 0; j < _resolution.Y; j += 2)
		{
			Gotoxy(i * 2, j);
			cout << "  ";
		}
		for (int j = 1; j < _resolution.Y; j += 2)
		{
			Gotoxy(_resolution.X - 2 - i * 2, j);
			cout << "  ";
		}
		Sleep(_delayTime);
	}
	SetColor();
}

void SelectBar::Erase(COORD pos)
{
	int xVal = _width % 2 == 0 ? _width / 2 : _width / 2 - 1;
	int yVal = _height % 2 == 0 ? _height / 2 : _height / 2 - 1;

	Gotoxy(pos.X - xVal, pos.Y - yVal);
	cout << " ";
	Gotoxy(pos.X + xVal, pos.Y - yVal);
	cout << "  " << endl;
	Gotoxy(pos.X - xVal, pos.Y + yVal);
	cout << " ";
	Gotoxy(pos.X + xVal, pos.Y + yVal);
	cout << "  " << endl;
}
