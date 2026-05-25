#pragma once
#include "Shape.h"
#include <iostream>

class Circle : public Shape
{
	double radius = 0.0;
	const int PI = 3.14;
public:
	Circle(double radius);
	double findArea() const override;
	double findParameter() const override;
	bool isInside(const Point& point) const override;
};

