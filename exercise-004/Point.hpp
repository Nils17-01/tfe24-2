#pragma once

#include <cmath>
#include <fmt/format.h>

// Simple Point class for exercise-004 (and reuse in exercise-005 tests)
class Point
{
public:
    int x;
    int y;

    // Default constructor: (0,0)
    Point() : x(0), y(0) {}

    // Parameterized constructor
    Point(int x_, int y_) : x(x_), y(y_) {}

    // Move the point by dx, dy
    void move(int dx, int dy) { x += dx; y += dy; }

    // Print the point as (x, y)
    void print() const { fmt::print("({}, {})\n", x, y); }

    // Euclidean distance to another point
    double distance_to(const Point &other) const
    {
        double dx = static_cast<double>(x - other.x);
        double dy = static_cast<double>(y - other.y);
        return std::sqrt(dx * dx + dy * dy);
    }
};
