#include <iostream>

int main()
{
    int **A;

    A = new int*[3];

    A[0] = new int[4]{1,2,3,4};
    A[1] = new int[4]{5,6,7,8};
    A[2] = new int[4]{9,10,11,12};

    delete []A;
    int *B = new int(1);
    std::cout << *B;
    int **C = new int*(B);
    std::cout << **C;

    delete B;
    delete C;

    return 0;
}