#include "raylib.h"
#include "doot.cpp"
#include "snake.cpp"

class GameScene
{
    public:
        GameScene(int width, int height) : _snake(Vector2{})
        {
            _width = width;
            _height = height;
            _snake = Snake(Vector2{(float)width/2, (float)height/2});
            _doot = Doot();
            _doot.PlaceRandomly();
        }

        void Update()
        {
            _timeSinceLastTick += GetFrameTime();  

            _snake.CalculateVelocity();

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

        GameScene* GetNext()
        {
            if(IsGameOver())
            {
                return new GameScene(_width, _height);
            }

            return this;
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

        bool IsGameOver()
        {
            return _snake.IsOutOfBounds(_width, _height) || _snake.IsHeadTouchingBody();
        }
};