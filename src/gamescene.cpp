#include "raylib.h"
#include "GameScene.h"
#include "Snake.h"
#include "Doot.h"
#include "GameOverScene.h"

GameScene::GameScene(int width, int height) {
    _width = width;
    _height = height;
    _snake = Snake(Vector2{(float) width / 2, (float) height / 2});
    _doot = Doot();
    _doot.PlaceRandomly();
}

void GameScene::Update() {
    _timeSinceLastTick += GetFrameTime();

    _snake.CalculateVelocity();

    if (_timeSinceLastTick < _timeBetweenTicks)
        return;

    _timeSinceLastTick -= _timeBetweenTicks;

    _snake.MoveHead();

    if (_snake.IsTouching(_doot.GetPosition())) {
        _doot.PlaceRandomly();
        SpeedUp();
    } else {
        _snake.MoveTail();
    }
}

void GameScene::Draw() {
    _snake.Draw();
    _doot.Draw();
}

Scene *GameScene::GetNext() {
    if (IsGameOver()) {
        return new GameOverScene(_width, _height);
    }

    return this;
}

void GameScene::SpeedUp() {
    _timeBetweenTicks *= 0.9f;
}

bool GameScene::IsGameOver() {
    return _snake.IsOutOfBounds(_width, _height) || _snake.IsHeadTouchingBody();
}
