#pragma once

#include <stdlib.h>
#include <math.h>

namespace Drawing
{
    struct Point
    {
        Point();

        Point(double x, double y);

        Point(int x, int y);

        Point(Point &other);

        double X;
        double Y;

#pragma region overloads

        Point operator+(const Point &other) const;

        Point operator+(const double scalar) const;

        Point operator-(const Point &other) const;

        Point operator-(const double scalar) const;

        Point &operator+=(const Point &other);

        Point &operator+=(const double scalar);

        Point &operator-=(const Point &other);

        Point &operator-=(const double scalar);

        bool operator>>(const Point &other) const;

        bool operator<<(const Point &other) const;

        bool operator==(const Point &other) const;

#pragma endregion
    };
}
