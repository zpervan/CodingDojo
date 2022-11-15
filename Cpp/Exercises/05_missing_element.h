#include <algorithm>
#include <vector>

bool isInsideRange(int N)
{
    constexpr int min_size{0};
    constexpr int max_size{100000};

    return (N >= min_size) && (N <= max_size);
}

int missingElement(std::vector<int>& A)
{
    // Assumption: N is an integer within the range [0..100,000] in which N is the vector size
    if (!isInsideRange(A.size()))
    {
        std::cout << "Vector size not within range\n";
        return -1;
    }

    std::sort(A.begin(), A.end());

    for (std::size_t i{1}; i < A.size(); ++i)
    {
        if (((A[i] - 1) != A[i - 1]))
        {
            std::cout << "Missing value is: " << A[i] - 1;
            return A[i] - 1;
        }
    }

    // Assumption: Each element of array A is an integer within the range [1..(N + 1)].
    std::cout << "All values correct";
    return 1;

    /* Codility solution */
    //    // N is size of the array
    //    unsigned long long int N = A.size();
    //    unsigned long long int sum = 0;
    //
    //    for (unsigned int i=0; i<N; i++) {
    //        sum += A[i];
    //    }
    //
    //    // Test the missing element could be 1 or N+1
    //    double answer = (N+1)*(N+2)/2 - sum;
    //
    //    return answer;
}
