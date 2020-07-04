#include <iostream>

int factorial(int n) {
  if (n == 0) {
    return 1;
  } else {
    std::cout << "N: " << n << "\n";
    return factorial(n - 1) * n;
  }
}

int main() {
  int x{5};

  auto result = factorial(x);
  std::cout << "Factorial: " << result << "\n";
  return 0;
}