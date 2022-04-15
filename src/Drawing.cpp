#include "../include/Drawing.h"

namespace Drawing
{
    Point::Point() : X(0), Y(0)
    {

    }

    Point::Point(double x, double y) : X(x), Y(y)
    {

    }

    Point::Point(int x, int y) : Point((double) x, (double) y)
    {

    }

    Point::Point(Point &other)
    {
        X = other.X;
        Y = other.Y;
    }

    Point Point::operator+(const Point &other) const
    {
        return {this->X + other.X, this->Y + other.Y};
    }

    Point Point::operator+(const double scalar) const
    {
        return {this->X + scalar, this->Y + scalar};
    }

    Point &Point::operator+=(const Point &other)
    {
        this->X += other.X;
        this->Y += other.Y;
        return *this;
    }

    Point &Point::operator+=(const double scalar)
    {
        this->X += scalar;
        this->Y += scalar;
        return *this;
    }

    Point Point::operator-(const Point &other) const
    {
        return {this->X - other.X, this->Y - other.Y};
    }

    Point Point::operator-(const double scalar) const
    {
        return {this->X - scalar, this->Y - scalar};
    }

    Point &Point::operator-=(const Point &other)
    {
        this->X -= other.X;
        this->Y -= other.Y;
        return *this;
    }

    Point &Point::operator-=(const double scalar)
    {
        this->X -= scalar;
        this->Y -= scalar;
        return *this;
    }

    bool Point::operator>>(const Point &other) const
    {
        return this->X > other.X || this->Y > other.Y;
    }

    bool Point::operator<<(const Point &other) const
    {
        return this->X < other.X || this->Y < other.Y;
    }

    bool Point::operator==(const Point &other) const
    {
        return this->X == other.X && this->Y == other.Y;
    }
}
