#include <iostream>
#include <vector>

class SillyClass {
  SillyClass OneMethod() { return SillyClass{}; }
  SillyClass SecondMethod() { return SillyClass{}; }
};

int main() {
  SillyClass silly_class;

  std::vector<int> intz{};
  intz.reserve(10);

  intz.emplace_back(1);

  return 0;
}
