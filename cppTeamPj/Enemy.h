#pragma once
#include "Entity.h"
class Enemy : public Entity
{
public:
	Enemy()
	{
		objectVisual = "��";
	}
	virtual void move() override;
};