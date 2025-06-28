#include "ScoreManager.h"
#include "Console.h"
#include <fcntl.h>
#include <io.h>
#include <sstream>


void ScoreManager::ScoreUp(int plusScore)
{
	score += plusScore;
	ScoreRender();
}

void ScoreManager::ScoreRender()
{
	COORD coord = GetConsoleResolution();
	Gotoxy(0, 0);
	int prevmode = _setmode(_fileno(stdout), _O_U16TEXT);
	wcout << L" _____ _____ _____ _____ _____" << endl;
	wcout << L"|   __|     |     | __  |   __|" << endl;
	wcout << L"|__   |   --|  |  |    -|   __|" << endl;
	wcout << L"|_____|_____|_____|__|__|_____|" << endl;
	wcout << L" _____________________________ " << endl;
	wcout << L"|                             |" << endl;
	wcout << L"|                             |" << endl;
	wcout << L"|                             |" << endl;
	wcout << L"|                             |" << endl;
	wcout << L"|_____________________________|" << endl;

	coord.X = 2;
	coord.Y = 5;
	scoreText = std::to_string(score);
	for (char c : scoreText) {
		int idx = c - '0';
		for (int line = 0; line < 4; ++line) {
			Gotoxy(coord.X, coord.Y + line);
			wcout << scoreTexts[idx][line];
		}
		coord.X += 6;
	}
	int curmode = _setmode(_fileno(stdout), prevmode);
}

int ScoreManager::GetScore()
{
	return score;
}

void ScoreManager::Initialize()
{
	score = 0;
}
