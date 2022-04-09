#ifndef CODINGDOJO_UTILITY_H
#define CODINGDOJO_UTILITY_H

#include <iostream>
#include <vector>

template <typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& values)
{
    for (const auto& value : values)
    {
        out << value << "\n";
    }

    out << "--- End of vector ---";

    return out;
}

#endif  // CODINGDOJO_UTILITY_H
