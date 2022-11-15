#include <vector>

void rotateNumbers(std::vector<int> & numbers)
{
    int temp = 0;
    int i = 0;
    int j = numbers.size() - 1;

    while((i != j) && (i < j))
    {
        temp = numbers.at(i);
        numbers.at(i) = numbers.at(j);
        numbers.at(j) = temp;
        ++i;
        --j;
    }

    for (const auto & number : numbers)
    {
        std::cout << number << " ";
    }
}