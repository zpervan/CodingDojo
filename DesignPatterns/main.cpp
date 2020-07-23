#include <iostream>

class SillyClass
{
    SillyClass &OneMethod() { return SillyClass{}; }
    SillyClass &SecondMethod() { return SillyClass{}; }
};

int main()
{
    SillyClass silly_class;

    return 0;
}