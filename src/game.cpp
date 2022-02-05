#include "raylib.h"
#include "raymath.h"
#include <cstdio>
#include "src/snake.cpp"
#include "src/doot.cpp"

class Game
{
    public:
        Game()
        {
            printf("Started a new game");
            _doot.PlaceRandomly();
        }

        void Update()
        {
            _snake.CalculateVelocity();

            _timeSinceLastTick += GetFrameTime();

            if(_timeSinceLastTick < _timeBetweenTicks)
                return;

            _timeSinceLastTick -= _timeBetweenTicks;

            _snake.Move();

            if(IsSnakeTouchingDoot())
            {
                _snake.Grow();
                _doot.PlaceRandomly();
                _timeBetweenTicks *= 0.9f;
            }
                
            if(_snake.IsHeadTouchingBody())
            {
                // game over, reset
                _timeBetweenTicks = 5;
            }
        }

        void Draw()
        {
            _snake.Draw();
            _doot.Draw();
        }

    private:
        Snake _snake;
        Doot _doot;
        float _timeSinceLastTick = 0;
        float _timeBetweenTicks = 1;

        bool IsSnakeTouchingDoot()
        {
            Vector2 snakePosition = _snake.GetPosition();
            Vector2 dootPosition = _doot.GetPosition();

            return snakePosition.x == dootPosition.x && snakePosition.y == dootPosition.y;
        }
};