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
		string rightVisual = "ก็";
		string leftVisual = "กๆ";
		string upVisual = "ก้";
		string downVisual = "ก่";
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