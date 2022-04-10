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
