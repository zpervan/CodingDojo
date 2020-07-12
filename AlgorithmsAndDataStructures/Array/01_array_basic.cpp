#include <array>
#include <iostream>
#include <vector>

int main() {
  int c_array[5];                 // C-Style array
  std::array<int, 5> cpp_array;   // C++ style array
  std::vector<int> cpp_vector(5); // C++ style array

  int *arr_ptr = new int[5]{1, 2, 3, 4, 5};
  int *new_ptr = new int[10]{2, 2, 2, 2, 255, 6, 9};

  delete[] arr_ptr;
  arr_ptr = new_ptr;
  new_ptr = nullptr;

  return 0;
}