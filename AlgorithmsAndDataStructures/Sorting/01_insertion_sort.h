#ifndef CODINGDOJO_01_INSERTION_SORT_H
#define CODINGDOJO_01_INSERTION_SORT_H

#include <vector>
#include <iostream>
#include "utility.h"

void insertionSort()
{
    std::vector<int> values{5, 2, 4, 6, 1, 3};


    for (std::size_t i = 1; i < values.size(); i++)
    {
        int key = values[i];
        std::size_t j = i - 1;
        while ((j >= 0) && (values[j] > key))
        {
            values[j + 1] = values[j];
            j = j - 1;
        }

        if (j + 1 < values.size())
        {
            values[j + 1] = key;
        }
    }

    std::cout << values;
}

#endif  // CODINGDOJO_01_INSERTION_SORT_H
