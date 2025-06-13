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
public:
	Enemy()
	{
		//objectVisual = ;
	}
	virtual void move() override;
};