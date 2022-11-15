#include "Sorting/single_header.h"

int main()
{
    /******* Values ********/
    std::vector<int> values{5, 2, 4, 6, 1, 3};

    /******* Sorting *******/
    // 01 - Insertion sort example
    insertionSort(Sorting::Increasing, values);
    insertionSort(Sorting::Decreasing, values);

    return 0;
}