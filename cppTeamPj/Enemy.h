#pragma once
#include <wincontypes.h>
#include "Entity.h"
#include "Console.h"

class Enemy : public Entity
{
private:
	// Visual을 담아둘 구조체
	struct Visual
	{
	public:
		string rightVisual = "→";
		string leftVisual = "←";
		string upVisual = "↑";
		string downVisual = "↓";
	};

	// 움직일 방향 저장해둘 COORD 배열
	COORD directionVectors[4];

	// enum class에 방향 만들어두기
	enum class Direction
	{
		RIGHT,
		LEFT,
		UP,
		DOWN
	};

	// Visual
	Visual visual;
	// 설정전에 기본
	Direction direction = Direction::RIGHT;
	//현재 위치 담아둘 COORD
	COORD currentPos;

public:
	// 생성자 옆에  : ~~는 맴버 이니셜라이저 리스트라고 부르고
	// 생성자 본문이 실행되기 전에 맴버 변수를 초기화시켜줍니다
	// (AI 사용부분)
	Enemy() : directionVectors { { 1, 0 }, { -1,0 }, { 0,-1 }, { 0,1 } }
	{
		SetEnemy();
	}

	// 에너미 초기값을 셋팅해주는 함수
	void SetEnemy();

	// 에너미를 생성해주는 함수
	void Spawn(COORD coord);

	// 에너미를 이동시켜주는 함수
	// 부모클래스에 있는 Move를 오버라이드해서 사용하는 함수
	virtual void Move() override;
};