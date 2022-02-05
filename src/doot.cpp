#include "raylib.h"
#include "raymath.h"
#include <cstdio>
#include "Doot.h"

Doot::Doot(){}

void Doot::PlaceRandomly()
{
    _position.x = (rand() % 12) * 10;
    _position.y = (rand() % 12) * 10;

    printf("Doot moved to: %3.1f, %3.1f \n", _position.x, _position.y);
}

void Doot::Draw()
{
    DrawRectangle(_position.x, _position.y, 10, 10, ORANGE);
}

Vector2 Doot::GetPosition()
{
    return _position;
}
