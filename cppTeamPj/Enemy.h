#pragma once
#include "Entity.h"
class Enemy : public Entity
{
private:
	struct Visual
	{
	public:
		string rightVisual = "��";
		string leftVisual = "��";
		string upVisual = "��";
		string downVisual = "��";
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