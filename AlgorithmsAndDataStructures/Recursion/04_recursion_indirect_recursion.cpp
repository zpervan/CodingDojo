#include <iostream>

void functionB(int n);

void functionA(int n) {
  if (n > 0) {
    std::cout << "Function A value N: " << n << "\n";
    functionB(n - 1);
  }
}

void functionB(int n) {
  if (n > 0) {
    std::cout << "Function B value N: " << n << "\n";
    functionA(n / 2);
  }
}

int main() {
  int x{20};

  functionA(x);

  return 0;
}
