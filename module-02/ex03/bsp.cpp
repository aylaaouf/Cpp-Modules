#include "Point.hpp"

Fixed area(Point const& a, Point const& b, Point const& c)
{
    return ((a.getX()*(b.getY()-c.getY()) +
             b.getX()*(c.getY()-a.getY()) +
             c.getX()*(a.getY()-b.getY())) / Fixed(2));
}

bool bsp( Point const& a, Point const& b, Point const& c, Point const& point) {
    Fixed A = area(a, b, c);
    Fixed A1 = area(point, b, c);
    Fixed A2 = area(a, point, c);
    Fixed A3 = area(a, b, point);

    if (A1 == 0 || A2 == 0 || A3 == 0)
        return (false);

    return ((A1 > 0 && A2 > 0 && A3 > 0) && A == (A1 + A2 + A3));
}