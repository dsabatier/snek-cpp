#include <cstdio>
#include "raylib.h"
#include "raymath.h"
#include "src/game.cpp"

int main()
{
    // Init
    const int width = 120;
    const int height = 120;

    InitWindow(width, height, "SNEK");
    SetTargetFPS(60);

    InitAudioDevice();

    // Load
    // Sound thud = LoadSound("res/thud.wav");

    // Gameplay scene
    Snake snake = Snake(Vector2{width/2, height/2});
    Doot doot = Doot();
    Game game = Game{snake, doot, width, height};

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        if(game.IsGameOver())
        {
            snake = Snake(Vector2{width/2, height/2});
            doot = Doot();
            game = Game{snake, doot, width, height};
        }
            
        game.Update();
        game.Draw();

        EndDrawing();
    }

    //UnloadSound(thud);

    CloseAudioDevice();
    CloseWindow();

    return 0;
}

