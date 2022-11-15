#include <iostream>
#include <vector>

std::vector<int> lookup_table(10, -1);
int result_n_2 = 0, result_n_1 = 0;

int fibonacci(int n) {
  if (n <= 1) {
    return n;
  }

  if (lookup_table.at(n - 2) == -1) {
    result_n_2 = lookup_table.at(n - 2) = fibonacci(n - 2);
  } else {
    result_n_2 = lookup_table.at(n - 2);
  }

  if (lookup_table.at(n - 1) == -1) {
    result_n_1 = lookup_table.at(n - 1) = fibonacci(n - 1);
  } else {
    result_n_1 = lookup_table.at(n - 1);
  }

  return result_n_2 + result_n_1;
}

int main() {
  fibonacci(10);
  std::cout << "Fibonacci elements: \n";
  for(const auto fibonacci_element : lookup_table)
  {
    std::cout << fibonacci_element << "\n";
  }
  return 0;
}
