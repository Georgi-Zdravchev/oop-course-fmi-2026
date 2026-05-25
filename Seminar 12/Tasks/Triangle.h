#pragma once
#include "Shape.h"

class Triangle : public Shape
{
	Point a, b, c;
public:
	Triangle(const Point& a, const Point& b, const Point& c);

	double findArea() const override;
	double findParameter() const override;
	bool isInside(const Point& point) const override;
};

