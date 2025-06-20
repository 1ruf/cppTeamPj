#pragma once
#include <windows.h>
#include <string>
#include <iostream>
#include "Entity.h"

using std::string;

class Enemy : public Entity
{
private:
	// Visual�� ��Ƶ� ����ü
	struct Visual
	{
		string rightVisual = "��";
		string leftVisual = "��";
		string upVisual = "��";
		string downVisual = "��";
	};

	// ������ ���� �����ص� COORD �迭
	// ���ʴ�� ������, ����, ��, �Ʒ�
	COORD directionVectors[4] = { {1,0}, {-1,0}, {0,1}, {0,-1} };

	// enum class�� ���� �����α�
	enum class Direction
	{
		RIGHT,
		LEFT,
		UP,
		DOWN
	};

	// Visual
	Visual visual;
	// �������� �⺻
	Direction direction = Direction::RIGHT;
	//���� ��ġ ��Ƶ� COORD
	COORD currentPos;

public:
	Enemy()
	{
		SetEnemy();
	}

	// ���ʹ� �ʱⰪ�� �������ִ� �Լ�
	void SetEnemy();

	// ���ʹ̸� �������ִ� �Լ�
	void Spawn(COORD coord);

	// ���ʹ̸� �̵������ִ� �Լ�
	// �θ�Ŭ������ �ִ� Move�� �������̵��ؼ� ����ϴ� �Լ�
	virtual void Move() override;
};