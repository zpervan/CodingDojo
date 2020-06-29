#include <iostream>

int functionStatic(int n)
{
  static int x = 0;
  if (n > 0)
  {
    x++;
    std::cout << "Static n: " << n << "\n";
    return functionStatic(n - 1) + x;
  }
  return 0;
}

int functionNoStatic(int n)
{
  if (n > 0)
  {
    std::cout << "Not static n: " << n << "\n";
    return functionNoStatic(n - 1) + n;
  }
  return 0;
}

int main()
{
  int number_n = 5;

  functionStatic(number_n);
  functionNoStatic(number_n);

  return 0;
}