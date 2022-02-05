#include "raylib.h"
#include "raymath.h"
#include <cstdio>
#include "Snake.h"

Snake::Snake(Vector2 startingPosition) {
    printf("Created player");
    _body.push_front(startingPosition);
}

void Snake::CalculateVelocity() {
    Vector2 input = GetInput();

    if (input.x == 0 && input.y == 0)
        return;

    _velocity = input;
}

void Snake::MoveHead() {
    _body.push_front(
            Vector2Add(_body[0], Vector2Scale(_velocity, 10)
            ));
}

void Snake::MoveTail() {
    _body.pop_back();
}

bool Snake::IsTouching(Vector2 point) {
    return _body[0].x == point.x && _body[0].y == point.y;
}

bool Snake::IsOutOfBounds(int width, int height) {
    Vector2 position = GetPosition();
    return position.x < 0 || position.x > width-1 || position.y < 0 || position.y >= height;
}

void Snake::Draw() {
    for (unsigned int i = 0; i < _body.size(); i++) {
        DrawRectangle(_body[i].x, _body[i].y, 10, 10, WHITE);
    }
}

Vector2 Snake::GetPosition() {
    return _body[0];
}

bool Snake::IsHeadTouchingBody() {
    for (unsigned int i = 1; i < _body.size(); i++) {
        if (_body[0].x == _body[i].x && _body[0].y == _body[i].y)
            return true;
    }

    return false;
}

Vector2 Snake::GetInput() {
    Vector2 direction{};
    if (IsKeyDown(KEY_LEFT) && _velocity.x != 1) direction.x -= 1.0;
    else if (IsKeyDown(KEY_RIGHT) && _velocity.x != -1) direction.x += 1.0;
    else if (IsKeyDown(KEY_UP) && _velocity.y != 1) direction.y -= 1.0;
    else if (IsKeyDown(KEY_DOWN) && _velocity.y != -1) direction.y += 1.0;

    return direction;
}
