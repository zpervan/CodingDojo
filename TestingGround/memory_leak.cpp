#include <iostream>
#include <vector>

/**
 * The commented area in the code below represent the solution
 **/

void FunctionWithMemoryLeak() {
  int *pointer_to_array = new int[5]{1, 2, 3, 4, 5};
  // delete[] pointer_to_array;
}

// Accessing element beyond allocated memory
void FunctionWithUndefinedBehavoir() {
  int *pointer_to_array = new int[5]{1, 2, 3, 4, 5};
  // for (std::size_t i = 0; i < (sizeof(int(5) / 4)); i++) {
  for (std::size_t i = 0; i < 6; i++) {
    std::cout << "Value: " << *(pointer_to_array + i) << std::endl;
  }
  delete[] pointer_to_array;
}

int main() {
  FunctionWithMemoryLeak();
  FunctionWithUndefinedBehavoir();
  return 0;
}