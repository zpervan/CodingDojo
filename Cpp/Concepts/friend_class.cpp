#include <iostream>

class FriendClass;

class BaseClass {
private:
  friend FriendClass;
  void CrazyFunction() { std::cout << "I'm called from base!" << std::endl; }
};

class FriendClass {
public:
  void CallBasesCrazyFunction(BaseClass &base) { base.CrazyFunction(); }
};

int main() {
  BaseClass hi;
  FriendClass friendz;
  friendz.CallBasesCrazyFunction(hi);
  return 0;
}