#include <iostream>
#include <array>


int CalculateMid(const int low, const int high) {
    return (high + low) / 2;
}

void BinarySearch(const std::array<int, 15> &sorted_list, const int key) {
    std::size_t low{0};
    std::size_t high{sorted_list.size() - 1};
    std::cout << "Low: " << low << ", high: " << high << "\n";

    while (true) {
        const std::size_t mid = CalculateMid(low, high);

        if (sorted_list[mid] == key) {
            std::cout << "Element found at position " << mid << "\n";
            break;
        }

        if (sorted_list[mid] < key) {
            low = mid + 1;
        }

        if (sorted_list[mid] > key) {
            high = mid - 1;
        }

        if (low > high) {
            std::cout << "Element NOT found\n";
            break;
        }
        std::cout << "Low: " << low << ", high: " << high << "\n";
    }
}


int main() {

    const std::array<int, 15> sorted_list{5, 7, 11, 23, 27, 31, 32, 33, 47, 49, 58, 59, 61, 63, 78};

    BinarySearch(sorted_list, 64);

    return 0;
}
