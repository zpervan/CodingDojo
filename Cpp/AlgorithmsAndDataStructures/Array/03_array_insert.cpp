#include <iostream>

void print(const int *array) {
  for (std::size_t i = 0; i < 10; i++)
    std::cout << "Element[" << i << "]: " << *(array + i) << "\n";
}

void insert(const std::size_t index, const int value, std::size_t array_length,
            int *array) {
  for (std::size_t i = array_length; i >= index; i--)
    *(array + i) = *(array + (i - 1));

  *(array + index) = value;
}

int main() {
  int *A = new int[10]{1, 2, 3, 4, 6};

  print(A);
  insert(4, 5, 5, A);
  print(A);
  delete[] A;
  A = nullptr;
  return 0;
}