#include "raylib.h"
#include "raymath.h"
#include <deque>
#include <cstdio>

class Snake {
    public:
        Snake(Vector2 startingPosition)
        {
            printf("Created player");
            _body.push_front(startingPosition);
        }

        void CalculateVelocity()
        {
            Vector2 input = GetInput();

            if(input.x == 0 && input.y == 0)
                return;

            _velocity = input;
        }

        void MoveHead()
        {             
            _body.push_front(
                Vector2Add(_body[0], Vector2Scale(_velocity, 10)
            ));
    
            printf("Head: %3.1f, %3.1f \n", _body[0].x, _body[0].y);
            for(int i = 1; i < _body.size(); i++)
            {
                printf("%i: %3.1f, %3.1f \n", i, _body[i].x, _body[i].y);
            }
        }

        void MoveTail()
        {
            _body.pop_back();
        }

        bool IsTouching(Vector2 point)
        {
            return _body[0].x == point.x && _body[0].y == point.y;
        }

        bool IsOutOfBounds(int width, int height)
        {
            Vector2 position = GetPosition();
            return position.x < 0 || position.x >= width || position.y < 0 || position.y >= height;
        }

        void Draw()
        {
            for(unsigned int i = 0; i < _body.size(); i++)
            {
                DrawRectangle(_body[i].x,_body[i].y, 10, 10, WHITE);
            }
        }

        Vector2 GetPosition()
        {
            return _body[0];
        }

        bool IsHeadTouchingBody()
        {
            for(int i = 1; i < _body.size(); i++)
            {
                if(_body[0].x == _body[i].x && _body[0].y == _body[i].y)
                    return true;
            }

            return false;
        }

    private:
        std::deque<Vector2> _body{};

        Vector2 _velocity{0, 0};

        Vector2 GetInput() 
        {
            Vector2 direction{};
            if(IsKeyDown(KEY_LEFT) && _velocity.x != 1) direction.x -= 1.0;
            else if(IsKeyDown(KEY_RIGHT) && _velocity.x != -1) direction.x += 1.0;
            else if(IsKeyDown(KEY_UP) && _velocity.y != 1) direction.y -= 1.0;
            else if(IsKeyDown(KEY_DOWN) && _velocity.y != -1) direction.y += 1.0;

            return direction;
        }
};