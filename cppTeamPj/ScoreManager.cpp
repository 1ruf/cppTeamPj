#include "ScoreManager.h"
#include "Console.h"


void ScoreManager::ScoreUp(int plusScore)
{
	score += plusScore;
	ScoreRender();    
}

void ScoreManager::ScoreRender()
{
	COORD coord = GetConsoleResolution();
	coord.X *= 0.7;
	coord.Y *= 0.2;
	Gotoxy(coord.X, coord.Y);
	cout << "현재 점수 : " << score;
}
