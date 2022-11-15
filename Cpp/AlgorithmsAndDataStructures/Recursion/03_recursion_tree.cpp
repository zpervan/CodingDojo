#include <iostream>

void function(int n) {
  std::cout << "Value N: " << n << "\n";
  if (n > 0) {
    std::cout << "First function call with N: " << n << "\n";
    function(n - 1);
    std::cout << "Second function call with N: " << n << "\n";
    function(n-1);
  }
}

int main() {

  int number{3};
  function(number);

  return 0;
}