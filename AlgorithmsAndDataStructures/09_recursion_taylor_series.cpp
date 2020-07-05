#include <iostream>

int taylor(int x, int n) {
  static int power = 1, factoriel = 1;
  double result;

  if (n == 0) {
    return 1;
  }
  result = taylor(x, n - 1);
  factoriel = factoriel * n;
  power = power * x;
  return result + power / factoriel;
}

int main() {
  int x{3};
  int n{3};
  std::cout << "Result: " << taylor(x, n) << "\n";
  return 0;
}