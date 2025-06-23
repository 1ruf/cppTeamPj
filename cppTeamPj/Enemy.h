#pragma once
#include <windows.h>
#include <string>
#include <iostream>
#include "Entity.h"

using std::string;

class Enemy : public Entity
{
private:
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

	Visual visual;
	Direction direction;
	COORD currentPos;
	COORD shieldPos;

public:

	Enemy()
	{
		SetEnemy();
	}

	void SetEnemy();

	virtual void Move() override;

	void Render();
	void Erase();

	bool CheckShield();
};