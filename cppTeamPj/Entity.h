#pragma once

#include <string>
using std::string;

class Entity
{
public:
	string objectVisual;
	virtual void move() abstract;
};