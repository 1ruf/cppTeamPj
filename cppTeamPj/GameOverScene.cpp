#include "GameOverScene.h"
#include <stdlib.h>

#include <fcntl.h>
#include <io.h>
#include "Console.h"
void GameOverScene(Scene& curScene, ScoreManager scoreManager, GameOverManager& gameoverManager)
{
	GameOverUpdate(curScene,scoreManager,gameoverManager);
	GameOverRender(curScene,gameoverManager);
}

void GameOverInit()
{
	system("cls");
}

void GameOverUpdate(Scene& curScene, ScoreManager scoreManager, GameOverManager& gameoverManager)
{
	COORD consoleSize = GetConsoleResolution();
	COORD selectedPos{ (consoleSize.X / 2) - 5, 2 * (consoleSize.Y / 3) + 1 };

	SelectRender(gameoverManager.selectedIdx,selectedPos);
}
void GameOverRender(Scene curScene,GameOverManager& gameoverManager)
{
	COORD consoleSize = GetConsoleResolution();

	Gotoxy(consoleSize.X / 2 - 9, consoleSize.Y / 2 - 25);
	cout << "G A M E   O V E R";
	
	RenderLogo(curScene, gameoverManager);

	COORD subtitlePos{ (consoleSize.X / 2) - 5, 2 * consoleSize.Y / 3 };

	Gotoxy(subtitlePos.X - 18, subtitlePos.Y);
	cout << "| 재시작 |" << endl;
	Gotoxy(subtitlePos.X - 2, subtitlePos.Y);
	cout << "| 메뉴 화면 |" << endl;
	Gotoxy(subtitlePos.X + 17, subtitlePos.Y);
	cout << "| 게임 종료 |" << endl;
}

void SelectRender(int index, COORD pos)
{
	switch (index)
	{
	case 0:
		Gotoxy(pos.X - 18, pos.Y);
		cout << "__________" << endl;
		break;
	case 1:
		Gotoxy(pos.X - 2, pos.Y);
		cout << "_____________" << endl;
		break;
	case 2:
		Gotoxy(pos.X + 17, pos.Y);
		cout << "_____________" << endl;
		break;
	default:
		break;
	}
}

void RenderLogo(Scene curScene,GameOverManager& manager)
{
	COORD consoleSize = GetConsoleResolution();

	Gotoxy(0, consoleSize.Y / 2 - 20);

	COLOR logoColor = COLOR::WHITE;
	switch (manager.fadeIdx)
	{
	case 0:
		logoColor = COLOR::WHITE;
		break;
	case 1:
		logoColor = COLOR::LIGHT_GRAY;
		break;
	case 2:
		logoColor = COLOR::GRAY;
		break;
	case 3:
		logoColor = COLOR::BLACK;
		break;
	case 4:
		logoColor = COLOR::GRAY;
		break;
	case 5:
		logoColor == COLOR::LIGHT_GRAY;
		break;
	default:
		break;
	}
	manager.fadeIdx++;
	if (manager.fadeIdx >= 6) manager.fadeIdx = 0;

	SetColor(logoColor, COLOR::BLACK);
	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);

	wcout << L"		  	      ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀		" << endl;
	wcout << L"		  	      ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⣶⣾⡿⠿⠿⠿⠿⠿⠿⢿⣷⣶⣦⣄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀		" << endl;
	wcout << L"		  	      ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣴⣾⡿⠟⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠛⠿⣷⣦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀		" << endl;
	wcout << L"		  	      ⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⡿⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⢿⣷⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀		" << endl;
	wcout << L"		  	      ⠀⠀⠀⠀⠀⠀⠀⢀⣾⡿⠋⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⠤⠤⠤⠤⢤⣄⣀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣿⣤⣴⣶⣿⣿⡄⠀⠀⠀	" << endl;
	wcout << L"		  	      ⠀⠀⠀⠀⠀⠀⣰⣿⠟⠀⠀⠀⠀⠀⠀⣠⡴⠚⠉⠁⠀⠀⠀⠀⠀⠀⠀⠉⠙⠶⣄⣀⣤⣴⣶⠿⠟⠛⠉⣁⠀⠀⢻⣧⠀⠀⠀	" << endl;
	wcout << L"		  	      ⠀⠀⠀⠀⠀⣰⣿⠏⠀⠀⠀⠀⠀⢠⡾⠋⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⣤⣴⡶⠿⠟⠛⢉⣁⣠⣤⡆⢾⣿⠿⣿⡄⠈⣿⡆⠀⠀	" << endl;
	wcout << L"		  	      ⠀⠀⠀⠀⢰⣿⠏⠀⠀⠀⠀⠀⣰⠋⠀⠀⠀⠀⣀⣠⣤⣴⡾⠿⠛⠛⣉⠁⢠⣄⠀⢸⣿⢻⣟⠋⠁⠘⣿⣄⣼⡷⠀⠸⣿⡀⠀	" << endl;
	wcout << L"		  	      ⠀⠀⠀⠀⣿⡿⠀⠀⠀⠀⠀⣸⣇⣠⣤⣶⡾⠿⠛⠋⠉⠀⠀⠀⠀⣾⡿⢿⣎⢿⣆⠈⣿⠘⣿⣶⡾⠇⢹⣿⠻⣷⡀⠀⢻⣧⠀	" << endl;
	wcout << L"		  	      ⠀⠀⠀⢰⣿⣇⣀⣠⣤⣶⠿⠿⠛⠋⢉⣀⢤⣴⣶⣿⠀⠀⠀⠀⠀⣿⡇⠈⢿⡆⢻⣆⣿⡀⢹⣷⡀⣀⣄⢿⡆⠙⠿⠆⠈⣿⡆	" << endl;
	wcout << L"		  	      ⣀⣤⣴⣾⠿⠟⠛⠉⠁⣠⡄⠀⣾⣆⢸⣿⡼⣿⡀⣀⣀⠀⠀⠀⠀⠸⣿⡀⢸⣿⠀⢻⣿⡇⠀⢿⠿⠛⠛⠉⣀⣤⣴⣶⡾⠿⠃	" << endl;
	wcout << L"		  	      ⣿⡏⠁⠀⣰⣶⣶⡄⠀⣿⣿⡄⠸⣿⣿⣿⣷⢻⣿⠟⠛⠀⠀⠀⠀⠀⠹⣿⣾⡿⠀⠀⠉⢁⣀⣤⣴⣶⠿⠟⠛⣿⡏⠀⠀⠀⠀	" << endl;
	wcout << L"		  	      ⢹⣷⠀⠀⣿⡏⠙⢋⡀⢻⡏⣿⣆⢿⡿⣿⢻⡎⣿⣦⣤⣶⡄⠀⠀⠀⠀⢀⣠⣤⣴⣶⠿⠛⣿⠋⠁⠀⠀⠀⢰⣿⠇⠀⠀⠀⠀	" << endl;
	wcout << L"		  	      ⠀⢿⣇⠀⢸⣷⠸⠿⣧⢸⣿⠿⢿⣞⣷⠀⠀⠿⠘⠛⠉⣁⣠⣤⣶⡶⠿⠛⠋⠁⠀⠀⠀⣼⠃⠀⠀⠀⠀⠀⣾⡿⠀⠀⠀⠀⠀	" << endl;
	wcout << L"		  	      ⠀⠘⣿⡄⠀⠻⣷⣤⣿⠿⣿⠀⠈⠛⢉⣀⣠⣤⣶⡾⠿⠛⠋⠉⠀⠀⠀⠀⠀⠀⠀⣠⡾⠁⠀⠀⠀⠀⠀⣼⡿⠃⠀⠀⠀⠀⠀	" << endl;
	wcout << L"		  	      ⠀⠀⢹⣷⠀⠀⠉⠛⢁⣀⣠⣤⣶⠾⠿⠻⢯⣉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⠾⠋⠀⠀⠀⠀⠀⢀⣼⣿⠃⠀⠀⠀⠀⠀⠀		" << endl;
	wcout << L"		  	      ⠀⠀⠀⢿⣧⣴⣶⠿⣿⣿⡉⠁⠀⠀⠀⠀⠀⠉⠙⠲⠶⠤⣤⣤⠤⠴⠶⠚⠉⠀⠀⠀⠀⠀⠀⠀⣠⣾⡿⠁⠀⠀⠀⠀⠀⠀⠀	" << endl;
	wcout << L"		  	      ⠀⠀⠀⠈⠉⠁⠀⠀⠈⠿⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣾⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀		" << endl;
	wcout << L"		  	      ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⢿⣷⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣶⣿⠟⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀		" << endl;
	wcout << L"		  	      ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠙⠻⢿⣷⣶⣤⣤⣤⣀⣀⣠⣤⣤⣶⣶⣿⠿⠛⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀		" << endl;
	wcout << L"		  	   ⠀   ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠛⠛⠛⠛⠛⠛⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀		" << endl;
	SetColor();
	int curmode = _setmode(_fileno(stdout), prevmode);
}

Scene GameSceneInput()
{
	return Scene();
}
