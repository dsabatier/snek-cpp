#include <cstdio>
#include "raylib.h"
#include "raymath.h"
#include "src/GameScene.cpp"

int main()
{
    // Init
    const int width = 140;
    const int height = 140;

    InitWindow(width, height, "SNEK ATE DOOT");
    SetTargetFPS(60);

    InitAudioDevice();

    // Load
    // Sound thud = LoadSound("res/thud.wav");

    //Scene* currentScene = new GameScene(width, height);
    Scene* currentScene = new GameScene(width, height);

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(BLACK);

        currentScene->Update();
        currentScene->Draw();
        currentScene = currentScene->GetNext();

        EndDrawing();
    }

    //UnloadSound(thud);

    CloseAudioDevice();
    CloseWindow();

    return 0;
}