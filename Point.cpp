#include "Point.h"

Point::Point(float px, float py) {
	x = px;
	y = py;
}

float Point::GetX() { return x; }
float Point::GetY() { return y; }
void Point::SetX(float px) { x = px; }
void Point::SetY(float py) { y = py; }