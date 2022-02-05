#include "raylib.h"
#include "raymath.h"
#include <deque>
#include <cstdio>

class Snake {
    public:
        Snake()
        {
            printf("Created player");
            _body.push_front(Vector2{120, 120});
        }

        void CalculateVelocity()
        {
            Vector2 input = GetInput();

            if(input.x == 0 && input.y == 0)
                return;

            _velocity = input;
        }

        void Move()
        {             
            _body.push_front(
                Vector2Add(_body[0], Vector2Scale(_velocity, 10)
            ));

            if(!_growNextFrame)
                _body.pop_back();
        
            _growNextFrame = false;

            
            printf("Head: %3.1f, %3.1f \n", _body[0].x, _body[0].y);
            for(int i = 1; i < _body.size(); i++)
            {
                printf("%i: %3.1f, %3.1f \n", i, _body[i].x, _body[i].y);
            }
        }

        void Grow()
        {
            _growNextFrame = true;
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
        bool _growNextFrame = false;
        std::deque<Vector2> _body{};

        Vector2 _velocity{1, 0};

        Vector2 GetInput() 
        {
            Vector2 direction{};
            if(IsKeyDown(KEY_LEFT)) direction.x -= 1.0;
            if(IsKeyDown(KEY_RIGHT)) direction.x += 1.0;
            if(IsKeyDown(KEY_UP)) direction.y -= 1.0;
            if(IsKeyDown(KEY_DOWN)) direction.y += 1.0;

            return direction;
        }
};