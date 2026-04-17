#pragma once
class Color
{
public:
	float r, g, b, a;

	Color() { r = 0.f; g = 0.f; b = 0.f; a = 0.f; }
	Color(float r, float g, float b, float a) :r(r), g(g), b(b), a(a) {}
	Color(float v) { r = g = b = a = v; }
	Color(const Color& c) { r = c.r; g = c.g; b = c.b; a = c.a; }
};

