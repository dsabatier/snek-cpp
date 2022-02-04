#include <cstdio>
#include "raylib.h"
#include "raymath.h"
#include "src/game.cpp"

int main()
{
    const int width = 250;
    const int height = 250;

    InitWindow(width, height, "SNEK");

    SetTargetFPS(60);

    Game game;

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        game.Update();
        game.Draw();

        EndDrawing();
    }

    return 0;
}

