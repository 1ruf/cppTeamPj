#pragma once
#include <string>
#include "Entity.h"
#include <windows.h>


using std::string;

class Enemy : public Entity
{
protected:

	struct Visual
	{
		string rightMoveVisual = "ก็";
		string leftMoveVisual = "กๆ";
		string upMoveVisual = "ก้";
		string downMoveVisual = "ก่";
	};

	COORD directionVectors[4] = { {-2,0}, {2,0}, {0,1}, {0,-1} };

	enum class Direction
	{
		RIGHT,
		LEFT,
		UP,
		DOWN
	};


	COORD currentPos;
	COORD shieldPos;
	Direction direction;
	Visual visual;

public:

	Enemy(int randNum)
	{
		SetEnemy(randNum);
	}

	void SetEnemy(int randNum);

	virtual void Move() override;

	virtual void Render();
	void Erase();

	bool CheckShield();
	bool CheckPlayer(COORD playerPos);
};