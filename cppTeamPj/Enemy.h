#pragma once
#include "Entity.h"
class Enemy : public Entity
{
private:
	struct Visual
	{
	public:
		string rightVisual = "กๆ";
		string leftVisual = "ก็";
		string upVisual = "ก่";
		string downVisual = "ก้";
	};

	enum class Direction
	{
		RIGHT,
		LEFT,
		UP,
		DOWN
	};

	Visual visual;
	Direction direction = Direction::RIGHT;

public:

	Enemy()
	{
		SetEnemy();
		Spawn();
		Move();
	}

	void SetEnemy();
	void Spawn();
	virtual void Move() override;
};