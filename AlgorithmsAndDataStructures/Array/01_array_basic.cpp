#include <array>
#include <iostream>
#include <vector>

int main() {
  // int c_array[5];                 // C-Style array
  // std::array<int, 5> cpp_array;   // C++ style array
  // std::vector<int> cpp_vector(5); // C++ style array

  // int *arr_ptr = new int[5]{1, 2, 3, 4, 5};
  // int *new_ptr = new int[10]{2, 2, 2, 2, 255, 6, 9};

  // delete[] arr_ptr;
  // arr_ptr = new_ptr;
  // new_ptr = nullptr;
  unsigned int x[4][3]{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
  unsigned int y[4]{1, 2, 3, 4};

  std::cout << "X+3 = " << x + 3;
  std::cout << "\nY+3 = " << y + 3;
  std::cout << "\n*(X+3) = " << *(x + 3);
  std::cout << "\n*(Y+3) = " << *(y + 3);
  std::cout << "\n*(X+2)+3 = " << *(x + 2) + 3;
  std::cout << "\n*(Y+2)+3 = " << *(y + 2) + 3;
  // std::cout << x + 3;
  // printf("%u,%u, %u", x + 3, *(x + 3), *(x + 2) + 3);
  return 0;
}