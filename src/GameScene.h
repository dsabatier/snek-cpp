#ifndef GAMESCENE_H
#define GAMESCENE_H

#include "raylib.h"
#include "Doot.h"
#include "Snake.h"
#include "Scene.h"

class GameScene : public Scene
{
    public:
        GameScene(int width, int height);
        void Update();
        void Draw();
        GameScene* GetNext();
    
    private:
        Snake _snake;
        Doot _doot;
        float _timeSinceLastTick = 0;
        float _timeBetweenTicks = 1;
        void SpeedUp();
        bool IsGameOver();
};

#endif