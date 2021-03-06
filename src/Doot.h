#ifndef DOOT_H
#define DOOT_H

#include "raylib.h"
#include "raymath.h"
#include <cstdio>

class Doot {
public:
    Doot();
    ~Doot();

    void PlaceRandomly();

    void Draw();

    Vector2 GetPosition();

private:
    Vector2 _position;
    Sound _munchSound;
};

#endif