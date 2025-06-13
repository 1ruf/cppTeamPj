#include "TitleScene.h"
#include "Console.h"
#include <fcntl.h>
#include <io.h>

void TitleScene(Scene& _eCurScene)
{
	TitleSceneRender();
	TitleSceneUpdate();
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
	wcout << L"	        |    ▄███▄▄▄▄███▄▄ ███▌ ███    ███  ▄███▄▄▄      ▄███▄▄▄▄██▀   |" << endl;
	wcout << L"	        |   ▀▀███▀▀▀▀███▀  ███▌ ███    ███ ▀▀███▀▀▀     ▀▀███▀▀▀▀▀     |" << endl;
	wcout << L"	        |     ███    ███   ███  ███    ███   ███    █▄  ▀███████████   |" << endl;
	wcout << L"	        |     ███    ███   ███  ███   ▄███   ███    ███   ███    ███   |" << endl;
	wcout << L"	        |     ███    █▀    █▀   ████████▀    ██████████   ███    ███   |" << endl;
	wcout << L"	        |                                                 ███    ███   |" << endl;

	int curmode = _setmode(_fileno(stdout), prevmode);
	COORD menuPos{ (consoleSize.X) / 2, 2 * (consoleSize.Y) / 3 };

	Gotoxy(menuPos.X - 18, menuPos.Y);
	cout << "게임 시작" << endl;
	Gotoxy(menuPos.X - 3, menuPos.Y);
	cout << "게임 정보" << endl;
	Gotoxy(menuPos.X + 12, menuPos.Y);
	cout << "게임 종료" << endl;
}

void TitleSceneUpdate()
{
	COORD consoleSize = GetConsoleResolution();
	COORD menuPos{ (consoleSize.X) / 2, 2 * (consoleSize.Y) / 3 };
	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);

	Gotoxy(menuPos.X - 21, menuPos.Y - 1);
	wcout << L"┏";
	Gotoxy(menuPos.X - 8, menuPos.Y - 1);
	wcout << L"┓" << endl;
	Gotoxy(menuPos.X - 21, menuPos.Y + 1);
	wcout << L"┗";
	Gotoxy(menuPos.X - 8, menuPos.Y + 1);
	wcout << L"┛" << endl;

	int curmode = _setmode(_fileno(stdout), prevmode);
}

Menu TitleSceneInput(Menu& _eCurMenu)
{
	COORD consoleSize = GetConsoleResolution();
	
	return Menu();
}
