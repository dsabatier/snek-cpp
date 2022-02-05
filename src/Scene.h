#ifndef SCENE_H
#define SCENE_H

class Scene
{
    public:
        Scene();
        Scene(int width, int height);
        virtual void Update();
        virtual void Draw();
        virtual Scene* GetNext();
    
    protected:
        int _width;
        int _height;
};

#endif