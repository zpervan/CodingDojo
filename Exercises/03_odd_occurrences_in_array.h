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

    std::list<int> paired_numbers;

    for(const auto & input_element : A)
    {
        // Erase existing element, else add to list
        const auto it = std::equal_range(paired_numbers.cbegin(), paired_numbers.cend(), input_element);

        if(it.first == paired_numbers.end())
        {
            paired_numbers.push_back(input_element);
        }
        else if(*it.first == input_element)
        {
            paired_numbers.erase(it.first);
        }
        else
        {
            paired_numbers.insert(it.first, input_element);
        }
    }

    /* Codility solution */
    //    unsigned long long int sum = 0;
    //
    //    for (unsigned int i=0; i<size; i++) {
    //        // A xor B xor A = B
    //        sum ^= A[i];
    //    }

    return paired_numbers.back();
}