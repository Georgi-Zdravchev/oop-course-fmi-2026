#include "Circle.h"

Circle::Circle(double radius) : radius(radius)
{
	if (radius <= 0)
		throw std::invalid_argument("Must be positive");
}

double Circle::findArea() const
{
	return PI*radius*radius;
}

double Circle::findParameter() const
{
	return 2*PI*radius;
}

bool Circle::isInside(const Point& point) const
{
	return (pow(point.x,2) + pow(point.y,2)) <= pow(radius,2);
}
