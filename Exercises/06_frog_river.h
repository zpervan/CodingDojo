#include <vector>
#include <set>
#include "utility.h"

constexpr int min_value = 1;
constexpr int max_value = 100000;

/* Optimal solution - perfect score */
int frogRiver(int X, std::vector<int> &A)
{
    if(!isInsideRange(X, min_value, max_value) || A.empty())
    {
        return -1;
    }

    std::set<int> temp;

    for(int i{0}; i < A.size(); ++i)
    {
        if(A[i] <= X)
        {
            temp.emplace(A[i]);
        }

        if(temp.size() == X)
        {
            std::cout << "Longest seconds: " << i;
            return i;
        }
    }

    return -1;
}
