#pragma once
class ScoreManager
{
private:
	int score = 0;

public:
	void ScoreUp(int plusScore);
	void ScoreRender();
};