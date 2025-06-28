#pragma once

#include <string>

class ScoreManager
{
private:
	int score = 0;
	std::string scoreText;

	// Raw String Litaral
	std::wstring scoreTexts[10][4] = {
    { L" ___ ", L"|   |", L"| | |", L"|___|" },  
    { L" ___ ", L"|_  |", L" _| |", L"|____|" }, 
    { L" ___ ", L"|_  |", L"|  _|", L"|___|" },  
    { L" ___ ", L"|_  |", L"|_  |", L"|___|" },  
    { L" ___ ", L"| | |", L"|_  |", L"  |_|" }, 
    { L" ___ ", L"|  _|", L"|_  |", L"|___|" },  
    { L" ___ ", L"|  _|", L"| . |", L"|___|" },  
    { L" ___ ", L"|_  |", L"  | |", L"  |_|" },  
    { L" ___ ", L"| . |", L"| . |", L"|___|" },  
    { L" ___ ", L"| . |", L"|_  |", L"|___|" }   
    };

public:
	void ScoreUp(int plusScore);
	void ScoreRender();
	int GetScore();
	void Initialize();
};