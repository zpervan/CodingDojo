#include <vector>

int passingCars(std::vector<int> &A)
{
    int value = 0;
    int result = 0;
    for(int i = 0; i < A.size(); ++i)
    {
        if(A[i] == 0)
        {
            ++value;
        }

        if(A[i] == 1)
        {
            result += value;
        }

        if(result > 100000000)
        {
            return -1;
        }
    }

    return result;
}
