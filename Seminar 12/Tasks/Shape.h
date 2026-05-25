#pragma once
#include "Point.h"

class Shape
{
public:
	virtual ~Shape() = default;

	virtual double findArea() const = 0;
	virtual double findParameter() const = 0;
	virtual bool isInside(const Point& point) const = 0;
};

