#include "raylib.h"
#include "raymath.h"
#include <cstdio>
#include "src/snake.cpp"

class Game
{
    public:
        Game()
        {
            printf("Started a new game");
        }

        void Update()
        {
            Vector2 input = GetInput();

            _snake.Move(input);
        }

        void Draw()
        {
            _snake.Draw();
        }

    private:
        Snake _snake;

        Vector2 GetInput() 
        {
            Vector2 direction{};
            if(IsKeyPressed(KEY_LEFT)) direction.x -= 1.0;
            if(IsKeyPressed(KEY_RIGHT)) direction.x += 1.0;
            if(IsKeyPressed(KEY_UP)) direction.y -= 1.0;
            if(IsKeyPressed(KEY_DOWN)) direction.y += 1.0;

            return direction;
        }

};