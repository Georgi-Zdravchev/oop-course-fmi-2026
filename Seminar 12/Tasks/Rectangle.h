#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
	double width = 0.0;
	double height = 0.0;
public:
	Rectangle(double width, double height);
	
	double findArea() const override;
	double findParameter() const override;
	bool isInside(const Point& point) const override;
};

