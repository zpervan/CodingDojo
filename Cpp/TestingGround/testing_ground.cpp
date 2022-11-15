#include <iostream>

template <class T> void PrintThisMan(T value) {
  std::cout << "I'm printing " << value << "\n";
}

template <typename T> T adder(T v) { return v; }

template <typename T, typename... Args> T adder(T first, Args... args) {
  return first + adder(args...);
}

int main() {
  PrintThisMan(10);
  PrintThisMan("Hello boi");
  PrintThisMan(10.5);

  PrintThisMan(adder(1, 2, 3, 4, 5, 6, 7));

  return 0;
}