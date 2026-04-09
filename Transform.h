#pragma once
#include "Vector2.h"

class Transform
{
public:
	Transform() {};
	Vector2 position {};
	float rotation {}; // Si ponemos las llaves al lado de la variable, estamos llamando a su constructor por defecto
	Vector2 scale = {1.f};
};

