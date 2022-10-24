#include <iostream>

class Base
{
  public:
    virtual void BaseFunction() = 0;
    void BaseFunctionNonVirtual() {
        std::cout << "Called from Base, boi!\n";
    }
};

class Derived : public Base
{
  public:
    void BaseFunction() override {
        std::cout << "Heya, hey!\n";
    }
};

int main()
{
    Derived d;
    d.BaseFunction();
    d.BaseFunctionNonVirtual();

    return 0;
}