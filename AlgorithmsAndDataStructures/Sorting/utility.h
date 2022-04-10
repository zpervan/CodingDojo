#ifndef CODINGDOJO_UTILITY_H
#define CODINGDOJO_UTILITY_H

#include <iostream>
#include <vector>

enum class Sorting
{
    Increasing = 0,
    Decreasing
};

template <typename T>
std::vector<T> generateValues(std::size_t numberOfValues)
{
    std::vector<T> values;
    values.reserve(numberOfValues);

    for(std::size_t i = 0; i < numberOfValues; i++)
    {
        values.emplace_back(rand() % numberOfValues);
    }

    return values;
}

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& values)
{
    for (const auto& value : values)
    {
        out << value << "\n";
    }

    out << "--- End of vector ---\n";

    return out;
}

#endif  // CODINGDOJO_UTILITY_H
