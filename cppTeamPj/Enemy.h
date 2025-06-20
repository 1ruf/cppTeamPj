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

	COORD directionVectors[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

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

public:
	Enemy()
	{
		SetEnemy();
	}

	void SetEnemy();

	void Spawn();

	virtual void Move() override;
};