#include "Triangle.h"
#include <cmath>

static double signedArea(const Point& p1,
    const Point& p2,
    const Point& p3)
{
    return (p2.x - p1.x) * (p3.y - p1.y)
        - (p3.x - p1.x) * (p2.y - p1.y);
}

static double dist(const Point& p, const Point& q) {
    double dx = p.x - q.x;
    double dy = p.y - q.y;
    return std::sqrt(dx * dx + dy * dy);
}

Triangle::Triangle(const Point& a, const Point& b, const Point& c) : a(a), b(b), c(c)
{
}

double Triangle::findArea() const
{
    return std::abs(signedArea(a, b, c)) / 2.0;
}

double Triangle::findParameter() const
{
    return dist(a, b) + dist(b, c) + dist(c, a);
}

bool Triangle::isInside(const Point& p) const {
    double d1 = signedArea(p, a, b);
    double d2 = signedArea(p, b, c);
    double d3 = signedArea(p, c, a);

    bool hasNeg = (d1 < 0) || (d2 < 0) || (d3 < 0);
    bool hasPos = (d1 > 0) || (d2 > 0) || (d3 > 0);

    return !(hasNeg && hasPos);
}
