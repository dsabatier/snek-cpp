#ifndef SCENE_H
#define SCENE_H

class Scene {
public:
    Scene() = default;

    Scene(int width, int height) : _width(width), _height(height) {

    }

    virtual void Enter()
    {

    }

    virtual void Exit()
    {

    }

    virtual void Update() {

    }

    virtual void Draw() {

    }

    virtual Scene *GetNext() {
        return nullptr;
    }

protected:
    int _width{};
    int _height{};
};

#endif