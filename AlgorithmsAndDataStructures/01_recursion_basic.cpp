#include <iostream>

void function(int n) {
  if (n > 0) {
    function(n - 1);
    std::cout << "N: " << n << std::endl;
  }
}

int main() {
  int x = 3;

  function(x);
  return 0;
}