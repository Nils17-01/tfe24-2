#pragma once

#include "point.hpp"
#include <cmath>

// Definitions for Point<T>

template <typename T>
Point<T>::Point(T x_, T y_) : x{x_}, y{y_} {}

template <typename T>
void Point<T>::move(T dx, T dy) { x += dx; y += dy; }

template <typename T>
auto Point<T>::distance_to(const Point &other) const -> dist_t {
  const dist_t dx = static_cast<dist_t>(x) - static_cast<dist_t>(other.x);
  const dist_t dy = static_cast<dist_t>(y) - static_cast<dist_t>(other.y);
  return std::hypot(dx, dy);
}

template <typename T>
bool Point<T>::operator==(const Point &rhs) const { return x == rhs.x && y == rhs.y; }

template <typename T>
bool Point<T>::operator!=(const Point &rhs) const { return !(*this == rhs); }
