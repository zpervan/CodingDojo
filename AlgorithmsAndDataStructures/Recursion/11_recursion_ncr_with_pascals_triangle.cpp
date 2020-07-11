#include <iostream>

int C(int n, int r) {
  if (n == r || r == 0)
    return 1;
  else
    return C(n - 1, r - 1) + C(n - 1, r);
}

int main() {
  std::cout << C(4, 2);
  return 0;
}