#pragma once
class Vector2
{
public:
	float x, y;

	Vector2() { x = 0.f; y = 0.f; }
	Vector2(float x, float y) :x(x), y(y) {}
	Vector2(float v) { x = y = v; }
	Vector2(const Vector2& v) { x = v.x; y = v.y; }

	Vector2 operator+(const Vector2& v2) {
		return Vector2(x + v2.x, y + v2.y);
	}

	Vector2 operator-(const Vector2& v2) {
		return Vector2(x - v2.x, y - v2.y);
	}

	Vector2 operator*(const float& scal) {
		return Vector2(x * scal, y * scal);
	}
};

