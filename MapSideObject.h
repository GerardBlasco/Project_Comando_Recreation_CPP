#pragma once
#include "Actor.h"
class MapSideObject : public Actor
{
public:
    MapSideObject(Scene* scene, class Background* map, bool alignLeft, Vector2 size);

    void AlignToSide();
    void AlignTop(Background* map);
    void SetPosition(float y);

private:
    class Background* map;
    bool alignLeft;
    Vector2 size;
};