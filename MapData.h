#pragma once
#include <vector>

class MapData
{
public:
    int width;
    int height;
    int tileSize;
    std::vector<int> data;

    MapData()
        : width(0), height(0), tileSize(0), data({})
    {
    }
    MapData(int width, int height, int tileSize, std::vector<int> data)
        : width(width), height(height), tileSize(tileSize), data(std::move(data))
    {
    }
};