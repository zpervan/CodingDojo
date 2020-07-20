#include <iostream>

void remove(const std::size_t index, int array[], std::size_t length) {

    for (std::size_t i = index; i < length - 1; i++) {
        array[i] = array[i + 1];
        i++;

        if(index == length - 1)
        {
            array[i] = 0;
        }
    }
}

int main() {
    int array[] = {1, 2, 3, 4, 5};


    remove(2, array, sizeof(array) / sizeof(int));

    return 0;
}
