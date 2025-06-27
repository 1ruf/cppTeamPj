#include "GameOverScene.h"
#include <stdlib.h>

#include <fcntl.h>
#include <io.h>
#include "Console.h"
void GameOverScene(Scene& curScene, ScoreManager scoreManager)
{
	GameOverUpdate(curScene,scoreManager);
	GameOverRender();
}

void GameOverInit()
{
	system("cls");
}

void GameOverUpdate(Scene& curScene, ScoreManager scoreManager)
{

}
void GameOverRender()
{

	COORD consoleSize = GetConsoleResolution();

	Gotoxy(consoleSize.X / 2 - 4, consoleSize.Y / 2 - 25);
	cout << "GAME OVER";
	Gotoxy(0, consoleSize.Y / 2 - 20);

	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);

	wcout << L"		  	       ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀		" << endl;
	wcout << L"		  	       ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣤⣶⣾⡿⠿⠿⠿⠿⠿⠿⢿⣷⣶⣦⣄⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀		" << endl;
	wcout << L"		  	       ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣴⣾⡿⠟⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠛⠿⣷⣦⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀		" << endl;
	wcout << L"		  	       ⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⣾⡿⠛⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⢿⣷⣤⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀		" << endl;
	wcout << L"		  	       ⠀⠀⠀⠀⠀⠀⠀⢀⣾⡿⠋⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⠤⠤⠤⠤⢤⣄⣀⠀⠀⠀⠀⠀⠀⠀⠙⢿⣿⣤⣴⣶⣿⣿⡄⠀⠀⠀	" << endl;
	wcout << L"		  	       ⠀⠀⠀⠀⠀⠀⣰⣿⠟⠀⠀⠀⠀⠀⠀⣠⡴⠚⠉⠁⠀⠀⠀⠀⠀⠀⠀⠉⠙⠶⣄⣀⣤⣴⣶⠿⠟⠛⠉⣁⠀⠀⢻⣧⠀⠀⠀	" << endl;
	wcout << L"		  	       ⠀⠀⠀⠀⠀⣰⣿⠏⠀⠀⠀⠀⠀⢠⡾⠋⠀⠀⠀⠀⠀⠀⠀⠀⣀⣠⣤⣴⡶⠿⠟⠛⢉⣁⣠⣤⡆⢾⣿⠿⣿⡄⠈⣿⡆⠀⠀	" << endl;
	wcout << L"		  	       ⠀⠀⠀⠀⢰⣿⠏⠀⠀⠀⠀⠀⣰⠋⠀⠀⠀⠀⣀⣠⣤⣴⡾⠿⠛⠛⣉⠁⢠⣄⠀⢸⣿⢻⣟⠋⠁⠘⣿⣄⣼⡷⠀⠸⣿⡀⠀	" << endl;
	wcout << L"		  	       ⠀⠀⠀⠀⣿⡿⠀⠀⠀⠀⠀⣸⣇⣠⣤⣶⡾⠿⠛⠋⠉⠀⠀⠀⠀⣾⡿⢿⣎⢿⣆⠈⣿⠘⣿⣶⡾⠇⢹⣿⠻⣷⡀⠀⢻⣧⠀	" << endl;
	wcout << L"		  	       ⠀⠀⠀⢰⣿⣇⣀⣠⣤⣶⠿⠿⠛⠋⢉⣀⢤⣴⣶⣿⠀⠀⠀⠀⠀⣿⡇⠈⢿⡆⢻⣆⣿⡀⢹⣷⡀⣀⣄⢿⡆⠙⠿⠆⠈⣿⡆	" << endl;
	wcout << L"		  	       ⣀⣤⣴⣾⠿⠟⠛⠉⠁⣠⡄⠀⣾⣆⢸⣿⡼⣿⡀⣀⣀⠀⠀⠀⠀⠸⣿⡀⢸⣿⠀⢻⣿⡇⠀⢿⠿⠛⠛⠉⣀⣤⣴⣶⡾⠿⠃	" << endl;
	wcout << L"		  	       ⣿⡏⠁⠀⣰⣶⣶⡄⠀⣿⣿⡄⠸⣿⣿⣿⣷⢻⣿⠟⠛⠀⠀⠀⠀⠀⠹⣿⣾⡿⠀⠀⠉⢁⣀⣤⣴⣶⠿⠟⠛⣿⡏⠀⠀⠀⠀	" << endl;
	wcout << L"		  	       ⢹⣷⠀⠀⣿⡏⠙⢋⡀⢻⡏⣿⣆⢿⡿⣿⢻⡎⣿⣦⣤⣶⡄⠀⠀⠀⠀⢀⣠⣤⣴⣶⠿⠛⣿⠋⠁⠀⠀⠀⢰⣿⠇⠀⠀⠀⠀	" << endl;
	wcout << L"		  	       ⠀⢿⣇⠀⢸⣷⠸⠿⣧⢸⣿⠿⢿⣞⣷⠀⠀⠿⠘⠛⠉⣁⣠⣤⣶⡶⠿⠛⠋⠁⠀⠀⠀⣼⠃⠀⠀⠀⠀⠀⣾⡿⠀⠀⠀⠀⠀	" << endl;
	wcout << L"		  	       ⠀⠘⣿⡄⠀⠻⣷⣤⣿⠿⣿⠀⠈⠛⢉⣀⣠⣤⣶⡾⠿⠛⠋⠉⠀⠀⠀⠀⠀⠀⠀⣠⡾⠁⠀⠀⠀⠀⠀⣼⡿⠃⠀⠀⠀⠀⠀	" << endl;
	wcout << L"		  	       ⠀⠀⢹⣷⠀⠀⠉⠛⢁⣀⣠⣤⣶⠾⠿⠻⢯⣉⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⠾⠋⠀⠀⠀⠀⠀⢀⣼⣿⠃⠀⠀⠀⠀⠀⠀		" << endl;
	wcout << L"		  	       ⠀⠀⠀⢿⣧⣴⣶⠿⣿⣿⡉⠁⠀⠀⠀⠀⠀⠉⠙⠲⠶⠤⣤⣤⠤⠴⠶⠚⠉⠀⠀⠀⠀⠀⠀⠀⣠⣾⡿⠁⠀⠀⠀⠀⠀⠀⠀	" << endl;
	wcout << L"		  	       ⠀⠀⠀⠈⠉⠁⠀⠀⠈⠿⣿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣾⡿⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀		" << endl;
	wcout << L"		  	       ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠻⢿⣷⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⣶⣿⠟⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀		" << endl;
	wcout << L"		  	       ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠉⠙⠻⢿⣷⣶⣤⣤⣤⣀⣀⣠⣤⣤⣶⣶⣿⠿⠛⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀		" << endl;
	wcout << L"		  	   ⠀    ⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠉⠉⠛⠛⠛⠛⠛⠛⠉⠉⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀		" << endl;
	
	COORD menuPos{ ((consoleSize.X) / 2) - 5, 2 * (consoleSize.Y) / 3 };

	
	int curmode = _setmode(_fileno(stdout), prevmode);

	Gotoxy(menuPos.X - 17, menuPos.Y);
	cout << "재시작" << endl;
	Gotoxy(menuPos.X + 17, menuPos.Y);
	cout << "게임 종료" << endl;
}
