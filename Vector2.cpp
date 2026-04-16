#include "Vector2.h"
#include "Game.h"
#include <iostream>

float Vector2::Module()
{
    return sqrt((x * x) + (y * y));
}

void Vector2::Normalize()
{
    float module = Module();

    x /= module;
    y /= module;
}

Vector2 Vector2::Normalized()
{
    float module = Module();

    return Vector2(x / module, y / module);
}

Vector2 Vector2::Bezier(Vector2 originPos, Vector2 middlePos, Vector2 targetPos, float time)
{
    Vector2 conexion0 = originPos + (middlePos - originPos) * time;
    Vector2 conexion1 = middlePos + (targetPos - middlePos) * time;

    Vector2 curve = conexion0 + (conexion1 - conexion0) * time;

    return curve;
}
