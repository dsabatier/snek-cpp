#include "raylib.h"
#include "raymath.h"
#include <deque>
#include <cstdio>

class Snake {
    public:
        Snake()
        {
            printf("Created player");
            _body.push_back(Vector2{10, 10});
        }

        void Move(Vector2 direction)
        {
            _body[0] = Vector2Add(_body[0], Vector2Scale(direction, 10));
        }

        void Draw()
        {
            for(int i = 0; i < _body.size(); i++)
            {
                DrawRectangle(_body[i].x,_body[i].y, 10, 10, WHITE);
            }
        }

    private:
        std::deque<Vector2> _body{};
        Vector2 _position;
};