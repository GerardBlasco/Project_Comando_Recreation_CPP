#include "MapSideObject.h"
#include "RectangleCollider.h"
#include "Background.h"

MapSideObject::MapSideObject(Scene* scene, Background* map, bool alignLeft, Vector2 size) : Actor(scene)
{
    this->map = map;
    this->alignLeft = alignLeft;
    this->size = size;
    AddComponent(new RectangleCollider(this, size.x, size.y, Color(255, 0, 0, 255), true));
    AlignToSide();
}

void MapSideObject::AlignToSide()
{
    float left = map->transform.position.x - map->width * 0.5f;
    float right = map->transform.position.x + map->width * 0.5f;
    float centerY = map->transform.position.y;

    if (alignLeft)
    {
        transform.position = Vector2(
            left + size.x * 0.5f,
            centerY
        );
    }
    else
    {
        transform.position = Vector2(
            right - size.x * 0.5f,
            centerY
        );
    }
}

void MapSideObject::AlignTop(Background* map)
{
    float top = map->transform.position.y - map->height * 0.5f;

    transform.position = Vector2(map->transform.position.x, top + size.y * 0.5f);
}

void MapSideObject::SetPosition(float y)
{
    transform.position.y = y;
}