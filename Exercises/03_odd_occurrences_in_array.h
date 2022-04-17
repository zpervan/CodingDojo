#include <algorithm>
#include <iostream>
#include <list>

bool isOddInsideRange(int N)
{
    constexpr int min_size{1};
    constexpr int max_size{1000000};

    return ((N % 2) != 0) && (N >= min_size) && (N <= max_size);
}

bool isValueOutsideRange(const std::vector<int> &A)
{
    constexpr int min_size{1};
    constexpr int max_size{1000000000};

    return std::any_of(A.cbegin(), A.cend(), [min_size, max_size](int e){ return (e < min_size) || (e > max_size);});
}

int oddOccurrencesInArray(std::vector<int> &A) {
    // Assumption: N is an odd integer within the range [1..1,000,000]
    if(!isOddInsideRange(A.size()))
    {
        //std::cout << "Array size is even or outside allowed boundary values.\n";
        return -1;
    }

    // Assumption: Each element of array A is an integer within the range [1..1,000,000,000]
    if(isValueOutsideRange(A))
    {
        //std::cout << "Array element value is outside allowed bound.\n";
        return -1;
    }

    unsigned long long int sum = 0;

    for (int i : A)
    {
        // A xor B xor A = B
        sum ^= i;
    }

    return sum;
}