#include <iostream>
#include <array>
int main()
{
  std::array<int, 3> arrayz;
  arrayz.fill(0);
  arrayz.fill(1);
  arrayz.fill(2);

  std::cout << "Array content: " << arrayz[0] << arrayz[1] << arrayz[2] << std::endl;
  return 0;
}