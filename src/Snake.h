#ifndef SNAKE_H
#define SNAKE_H

#include "raylib.h"
#include "raymath.h"
#include <deque>
#include <cstdio>

class Snake 
{
    public:
        Snake();
        Snake(Vector2 startingPosition);
        void CalculateVelocity();
        void MoveHead();
        void MoveTail();
        bool IsTouching(Vector2 point);
        bool IsOutOfBounds(int width, int height);
        void Draw();
        Vector2 GetPosition();
        bool IsHeadTouchingBody();

    private:
        std::deque<Vector2> _body{};
        Vector2 _velocity{0, 0};
        Vector2 GetInput();
};

#endif