#pragma once

// Generic Point<T> header (declaration). Implementations are in point_impl.hpp

#include <type_traits>
#include <utility>
#include <cmath>
#include <concepts> // not used for constraints, kept commented: C++17 must not use concepts

template <typename T>
class Point {
  static_assert(std::is_arithmetic<T>::value, "Point<T>: T must be arithmetic");
public:
  T x{};
  T y{};

  Point() = default;                      // x = T{}, y = T{}
  Point(T x_, T y_);                     // declared, defined in point_impl.hpp

  void move(T dx, T dy);                 // declared

  using dist_t = std::common_type_t<T, double>;
  auto distance_to(const Point &other) const -> dist_t; // declared

  bool operator==(const Point &rhs) const;
  bool operator!=(const Point &rhs) const;

  // Optional: arithmetic operators can be added later
};

// include the implementation for templates
#include "point_impl.hpp"
