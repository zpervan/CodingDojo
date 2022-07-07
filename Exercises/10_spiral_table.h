#include <numeric>
#include <vector>

// @TODO: The solution is not optimal as we iterate through elements which are already assigned.
//        Leverage index bookkeeping for a more optimal solution.

void spiralTable()
{
    int row_index = 5;
    int column_index = 5;

    // Create a matrix filled with zeros
    std::vector<std::vector<int>> result(row_index, std::vector<int>(column_index));

    // Decrement the index by 1 for proper array indexing
    --row_index;
    --column_index;

    // Assign the max size of the vector, so we know where our borders are
    const int row_max_size = row_index;
    const int column_max_size = column_index;

    // Value fot the cyclic matrix table
    int value = 1;

    do{
        // Assign values in a row negative manner
        for(int i{column_index}; i >= 0; --i)
        {
            // If the cell contains a zero, let's fill it
            if(result[row_index][i] == 0)
            {
                result[row_index][i] = value++;
            }
        }

        // Assign values in a column negative manner
        for(int j{row_index}; j >= 0; --j)
        {
            if(result[j][column_max_size - column_index] == 0)
            {
                result[j][column_max_size - column_index] = value++;
            }
        }

        // Assign values until the row border in a row positive manner
        for(int i{0}; i <= row_max_size; ++i)
        {
            if(result[row_max_size - row_index][i] == 0)
            {
                result[row_max_size - row_index][i] = value++;
            }
        }

        // Assign values until the row border in a row positive manner
        for(int j{0}; j <= column_max_size; ++j)
        {
            if(result[j][column_index] == 0)
            {
                result[j][column_index] = value++;
            }
        }

        column_index -= 1;
        row_index -= 1;
    }while(row_index >= 0 && column_index >= 0);


    // Print it
    for(const auto& row : result)
    {
        for (const auto column : row)
        {
            std::cout << column << " ";
        }
        std::cout << "\n";
    }
}
