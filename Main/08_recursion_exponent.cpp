#include <iostream>

int exponent_unoptimized(int m, int n) {
  std::cout << "Base: " << m << "\n";
  std::cout << "Exponent: " << n << "\n";
  if (n == 0) {
    return 1;
  } else {
    return exponent_unoptimized(m, n - 1) * m;
  }
}

int exponent_optimized(int m, int n) {
  std::cout << "Base: " << m << "\n";
  std::cout << "Exponent: " << n << "\n";
  if (n == 0) {
    return 1;
  }

  if (n % 2 == 0) {
    return exponent_optimized(m * m, n / 2);
  } else {
    return exponent_optimized(m * m, (n - 1) / 2) * m;
  }
}

int main() {
  int m{2};
  int n{8};
  std::cout << "Result unoptimized:\n" << exponent_unoptimized(m, n);

  n = 9;
  std::cout << "\nResult optimized: " << exponent_optimized(m, n);

  return 0;
}