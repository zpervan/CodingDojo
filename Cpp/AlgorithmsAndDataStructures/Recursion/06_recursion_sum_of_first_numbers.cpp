#include <iostream>

int function(int n) {
  std::cout << "Sum: " << n << "\n";
  if (n == 0) {
    return 0;
  } else {
    return function(n - 1) + n;
  }
}

int main() {
  int x{5};
  std::cout << function(x);
  return 0;
}
