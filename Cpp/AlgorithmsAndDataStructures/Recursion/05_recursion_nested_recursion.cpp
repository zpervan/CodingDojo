#include <iostream>

int function(int n) {
  std::cout << "N: " << n << "\n";
  if (n > 100) {

    std::cout << "If N: " << n << "\n";
    return n - 10;

  } else {

    std::cout << "Else N: " << n << "\n";
    return function(function(n + 11));
  }
}

int main() {
  int x{95};
  int nested_function_result = function(x);
  std::cout << "Result: " << nested_function_result << "\n";
  return 0;
}