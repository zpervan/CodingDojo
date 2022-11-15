#ifndef CODINGDOJO_01_INSERTION_SORT_H
#define CODINGDOJO_01_INSERTION_SORT_H

#include <iostream>
#include <vector>

#include "utility.h"

namespace
{
template <typename T>
void increasing(std::vector<T>& values)
{
    std::size_t j;
    int key;

    for (std::size_t i = 1; i < values.size(); i++)
    {
        key = values[i];
        j = i - 1;
        while ((j >= 0) && (values[j] > key))
        {
            values[j + 1] = values[j];
            --j;
        }

        if (j + 1 < values.size())
        {
            values[j + 1] = key;
        }
    }

    std::cout << values;
}

template <typename T>
void decreasing(std::vector<T>& values)
{
    std::size_t i = values.size() - 2;
    std::size_t j;
    int key;
    do
    {
        key = values[i];
        j = i + 1;
        while ((j < values.size()) && (values[j] > key))
        {
            values[j - 1] = values[j];
            ++j;
        }

        values[j - 1] = key;
        --i;
    } while ((i >= 0) && (i < values.size() - 1));

    std::cout << values;
}
}  // namespace

template <typename T>
void insertionSort(Sorting type, std::vector<T> values)
{
    switch (type)
    {
        case Sorting::Increasing:
            increasing(values);
            break;
        case Sorting::Decreasing:
            decreasing(values);
            break;
        default:
            std::cout << "No valid sorting type is defined";
    }
}

#endif  // CODINGDOJO_01_INSERTION_SORT_H
