#include "raylib.h"
#include "raymath.h"
#include <cstdio>

class Doot {
    public:
        Doot(){}

        void PlaceRandomly()
        {
            _position.x = (rand() % 25) * 10;
            _position.y = (rand() % 25) * 10;

            printf("Doot moved to: %3.1f, %3.1f \n", _position.x, _position.y);
        }

        void Draw()
        {
            DrawRectangle(_position.x, _position.y, 10, 10, YELLOW);
        }

        Vector2 GetPosition()
        {
            return _position;
        }

    private:
        Vector2 _position;
};