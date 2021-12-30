#include <iostream>

typedef int (*IntFunction)(int, int);
typedef float (*FloatFunction)(float, float);

int CalculateInt(int a, int b) { return a + b; }
float CalculateFloat(float a, float b) { return a + b; }

int main() {
  IntFunction intFunction{&CalculateInt};
  std::cout << "[INT] Result: " << intFunction(1, 2);

  FloatFunction floatFunction{&CalculateFloat};
  std::cout << "[FLOAT] Result: " << floatFunction(1.5, 2.5);
  
  return EXIT_SUCCESS;
}