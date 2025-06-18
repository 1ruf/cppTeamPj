#pragma once
#include <wincontypes.h>
#include "Entity.h"
#include "Console.h"

class Enemy : public Entity
{
private:
	// Visual�� ��Ƶ� ����ü
	struct Visual
	{
	public:
		string rightVisual = "��";
		string leftVisual = "��";
		string upVisual = "��";
		string downVisual = "��";
	};

	// ������ ���� �����ص� COORD �迭
	COORD directionVectors[4];

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
	// ������ ����  : ~~�� �ɹ� �̴ϼȶ����� ����Ʈ��� �θ���
	// ������ ������ ����Ǳ� ���� �ɹ� ������ �ʱ�ȭ�����ݴϴ�
	// (AI ���κ�)
	Enemy() : directionVectors { { 1, 0 }, { -1,0 }, { 0,-1 }, { 0,1 } }
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