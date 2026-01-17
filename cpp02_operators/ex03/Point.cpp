#include "Point.hpp"

Point::Point() : x(0), y(0) { }

Point::Point( const float _x, const float _y ) : x(_x), y(_y) { }

Point::Point( const Point& other) : x(other.x), y(other.y) { }

Fixed Point::getX() const {
    return (x);
}

Fixed Point::getY() const {
    return (y);
}

Point::~Point() { }