#pragma once
#include <iostream>
#include "Vector2.h"

class ObstacleData
{
public:
    int id;
    std::string name;
    Vector2 size;

    ObstacleData(int id, const std::string& name, Vector2 size)
        : id(id), name(name), size(size) {
    }

    static const ObstacleData& Get(int id);
    static int Count();
};