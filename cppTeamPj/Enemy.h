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
public:
	Enemy()
	{
		//objectVisual = ;
	}
	virtual void move() override;
};