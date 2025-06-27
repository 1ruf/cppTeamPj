#pragma once

#include <string>

class ScoreManager
{
private:
	int score = 0;
	std::string scoreText;

	// Raw String Litaral
	std::wstring scoreTexts[10] = {
		LR"( ___ 
|   | 
| | | 
|___| )",
		LR"( ___   
|_  |  
 _| | 
|____|)",
		LR"( ___ 
|_  | 
|  _| 
|___| )",
		LR"( ___ 
|_  | 
|_  | 
|___| )",
		LR"( ___ 
| | | 
|_  | 
  |_| )",
		LR"( ___ 
|  _| 
|_  | 
|___| )",
		LR"( ___ 
|  _| 
| . | 
|___| )",
		LR"( ___ 
|_  | 
  | | 
  |_| )",
		LR"( ___ 
| . | 
| . | 
|___| )",
		LR"( ___ 
| . | 
|_  | 
|___| )"
	};

public:
	void ScoreUp(int plusScore);
	void ScoreRender();
};