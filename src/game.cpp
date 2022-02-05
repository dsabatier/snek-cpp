#include "raylib.h"
#include "raymath.h"
#include <cstdio>
#include "src/snake.cpp"
#include "src/doot.cpp"

class Game
{
    public:
        Game(Snake snake, Doot doot, int width, int height) : _snake(Vector2{0,0}), _doot()
        {
            _snake = snake;
            _doot = doot;
            _width = width;
            _height = height;

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
            
            _snake.MoveHead();

            if(_snake.IsTouching(_doot.GetPosition()))
            {
                _doot.PlaceRandomly();
                SpeedUp();
            }
            else
            {
                _snake.MoveTail();
            }
        }

        void Draw()
        {
            _snake.Draw();
            _doot.Draw();
        }

        bool IsGameOver()
        {
            return _snake.IsOutOfBounds(_width, _height) || _snake.IsHeadTouchingBody();
        }

    private:
        Snake _snake;
        Doot _doot;
        int _width;
        int _height;
        float _timeSinceLastTick = 0;
        float _timeBetweenTicks = 1;

        void SpeedUp()
        {
            _timeBetweenTicks *= 0.9f;
        }
};