#pragma once
#include"KeyContoller.h"
#include"Enums.h"

typedef struct _pos
{
    int x;
    int y;

    bool operator==(const _pos& _other) const
    {
        return (x == _other.x && y == _other.y);
    }
} POS, * PPOS;


void HandleInput(POS& _pos, Menu& _menu);
