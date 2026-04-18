#pragma once
class Vector2
{
public:
	float x, y;

	Vector2() { x = 0.f; y = 0.f; }
	Vector2(float x, float y) :x(x), y(y) {}
	Vector2(float v) { x = y = v; }
	Vector2(const Vector2& v) { x = v.x; y = v.y; }

	float Module();
	void Normalize();
	Vector2 Normalized();

	Vector2 operator+(const Vector2& v2) {
		return Vector2(x + v2.x, y + v2.y);
	}

	Vector2 operator-(const Vector2& v2) {
		return Vector2(x - v2.x, y - v2.y);
	}

	Vector2 operator*(const float& scal) {
		return Vector2(x * scal, y * scal);
	}

	Vector2 operator+=(const Vector2& v2) {

		x += v2.x;
		y += v2.y;

		return *this;
	}

	Vector2 operator-=(const Vector2& v2) {

		x -= v2.x;
		y -= v2.y;

		return *this;
	}

	static Vector2 Bezier(Vector2 originPos, Vector2 middlePos, Vector2 targetPos, float time);

	static int DirectionIndex(Vector2 direction, int numDirections);
};

