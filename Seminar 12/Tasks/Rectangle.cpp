#include "Rectangle.h"
#include <stdexcept>

Rectangle::Rectangle(double width, double height) : width(width), height(height)
{
	if (width <= 0 || height <= 0)
		throw std::invalid_argument("Width and height must be positive.");
}

double Rectangle::findArea() const
{
	return width*height;
}

double Rectangle::findParameter() const
{
	return 2 * (width+height);
}

bool Rectangle::isInside(const Point& point) const
{
	return point.x <= width && point.y <= height;
}
