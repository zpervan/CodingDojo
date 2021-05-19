#include <cmath>
#include <fmt/format.h>

template <typename T> struct Vector2D {
  T x;
  T y;
};

template <typename T> struct Vector3D {
  T x;
  T y;
  T z;
};

template <typename T>
Vector2D<T> operator+(const Vector2D<T> &lhs, const Vector2D<T> &rhs) {
  return {lhs.x + rhs.x, lhs.y + rhs.y};
}

template <typename T, typename... Args>
Vector2D<T> operator+(const Vector2D<T> &first, Args... args) {
  return {first + args...};
}

template <typename T>
Vector2D<T> operator-(const Vector2D<T> &lhs, const Vector2D<T> &rhs) {
  return {lhs.x - rhs.x, lhs.y - rhs.y};
}

template <typename T, typename... Args>
Vector2D<T> operator-(const Vector2D<T> &first, Args... args) {
  return {first - args...};
}

template <typename T>
double operator*(const Vector2D<T> &lhs, const Vector2D<T> &rhs) {
  return lhs.x * rhs.x + lhs.y * rhs.y;
}

template <typename T>
double CalculateVectorMagnitude(const Vector2D<T> &vector) {
  return std::sqrt(std::pow(vector.x, static_cast<T>(2)) +
                   std::pow(vector.y, static_cast<T>(2)));
}

template <typename T>
double CalculateVectorMagnitude(const Vector3D<T> &vector) {
  return std::sqrt(std::pow(vector.x, static_cast<T>(2)) +
                   std::pow(vector.y, static_cast<T>(2)) +
                   std::pow(vector.z, static_cast<T>(2)));
}

template <typename T> void PrintVectorValues(const Vector2D<T> &vector) {
  fmt::print("2D vector values: [{} {}]\n", vector.x, vector.y);
}

template <typename T> void PrintVectorValues(const Vector3D<T> &vector) {
  fmt::print("3D vector values: [{} {} {}]\n", vector.x, vector.y, vector.z);
}

int main() {
  Vector2D<int> a{1, 6};
  Vector2D<int> b{3, 4};
  Vector2D<int> c{6, 9};
  Vector2D<int> d{4, 2};

  fmt::print("Vector magnitude of a is {}\n", CalculateVectorMagnitude(a));
  fmt::print("Vector magnitude of b is {}\n", CalculateVectorMagnitude(b));

  Vector2D<int> addition = a + b + c + d;
  PrintVectorValues(addition);

  Vector2D<int> subtraction = a - b - c - d;
  PrintVectorValues(subtraction);

  const auto product = a * b;
  fmt::print("The product of a * b multiplication is {}", product);

  return 0;
}