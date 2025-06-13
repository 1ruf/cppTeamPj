#pragma once
#include "Entity.h"
class Enemy : public Entity
{
public:
	Enemy()
	{
		objectVisual = "¡æ";
	}
	virtual void move() override;
};