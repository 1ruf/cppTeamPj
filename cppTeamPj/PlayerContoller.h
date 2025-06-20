#pragma once
#include"Enums.h"
#include"KeyContoller.h"
#include "Player.h"

typedef struct _pos
{
    int x;
    int y;

    bool operator==(const _pos& _other) const
    {
        return (x == _other.x && y == _other.y);
    }
} POS, * PPOS;


void HandleInput(Player& player, Scene& _curScene);
