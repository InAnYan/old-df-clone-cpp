#include "Point.hpp"

namespace Framework
{
    Point::Point(float x, float y)
        : x(x), y(y)
    {
    }

    Rect Point::ToTileRect(const Point& tileSize) const
    {
        return {x * tileSize.x, y * tileSize.y, tileSize.x, tileSize.y};
    }

    Point& Point::operator+=(const Point& other)
    {
        this->x += other.x;
        this->y += other.y;
        return *this;
    }

    Point& Point::operator*=(const Point& other)
    {
        this->x *= other.x;
        this->y *= other.y;
        return *this;
    }

    Point& Point::operator/=(const Point& other)
    {
        this->x /= other.x;
        this->y /= other.y;
        return *this;
    }

    Point& Point::operator*=(float factor)
    {
        this->x *= factor;
        this->y *= factor;
        return *this;
    }

    Point operator+(const Point& a, const Point& b)
    {
        Point a1(a);
        return a1 += b;
    }

    Point operator*(const Point& a, const Point& b)
    {
        Point a1(a);
        return a1 *= b;
    }

    Point operator/(const Point& a, const Point& b)
    {
        Point a1(a);
        return a1 /= b;
    }

    Point operator*(const Point& a, float f)
    {
        Point a1(a);
        return a1 *= f;
    }
}
