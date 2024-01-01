//
// Created by rusla on 31.12.2023.
//

#ifndef POINT_HPP
#define POINT_HPP

#include "Rect.hpp"

namespace Framework
{
    struct Point
    {
        int x;
        int y;

        Point(int x, int y);

        [[nodiscard]] Rect ToTileRect(const Point& tileSize) const;

        Point& operator+=(const Point& other);
        Point& operator*=(const Point& other);
        Point& operator/=(const Point& other);

        Point& operator*=(int factor);
    };

    Point operator+(const Point& a, const Point& b);
    Point operator*(const Point& a, const Point& b);
    Point operator/(const Point& a, const Point& b);

    Point operator*(const Point& a, int f);
}

#endif //POINT_HPP
