#include <iostream>
#include <string>

template<typename T>
class Print {
public:
    void operator()(const T &rhs) {
        std::cout << rhs << std::endl;
    }
};

int main() {
    Print<std::string> print;
    print("Hi");

    Print<double> printz;
    printz(2.0);
    return 0;
}
