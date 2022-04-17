/*
An array A consisting of N integers is given. Rotation of the array means that each element is shifted right by one
index, and the last element of the array is moved to the first place. For example, the rotation of array A = [3, 8, 9,
7, 6] is [6, 3, 8, 9, 7] (elements are shifted right by one index and 6 is moved to the first place).

The goal is to rotate array A K times; that is, each element of A will be shifted to the right K times.

         Write a function:

    vector<int> solution(vector<int> &A, int K);

that, given an array A consisting of N integers and an integer K, returns the array A rotated K times.

                                                                  For example, given

        A = [3, 8, 9, 7, 6]
    K = 3
        the function should return [9, 7, 6, 3, 8]. Three rotations were made:

    [3, 8, 9, 7, 6] -> [6, 3, 8, 9, 7]
              [6, 3, 8, 9, 7] -> [7, 6, 3, 8, 9]
              [7, 6, 3, 8, 9] -> [9, 7, 6, 3, 8]
    For another example, given

            A = [0, 0, 0]
        K = 1
        the function should return [0, 0, 0]

        Given

            A = [1, 2, 3, 4]
        K = 4
            the function should return [1, 2, 3, 4]

            Assume that:

    N and K are integers within the range [0..100];
each element of array A is an integer within the range [−1,000..1,000].
    In your solution, focus on correctness. The performance of your solution will not be the focus of the assessment.
*/

#include <algorithm>
#include <iostream>
#include <vector>

#define MIN_SHIFT_NUM 0
#define MAX_SHIFT_NUM 100
#define MIN_ARRAY_ELEMENT -1000
#define MAX_ARRAY_ELEMENT 1000

std::vector<int> cyclicRotation(std::vector<int>& A, int K)
{
    // Assumption: N and K are integers within the range [0..100]
    if ((A.size() > MAX_SHIFT_NUM) || (K > MAX_SHIFT_NUM) || (K < MIN_SHIFT_NUM))
    {
        std::cout << "N or K is outside boundaries [0..100]\n";
        return {};
    }

    // Assumption: Each element of array A is an integer within the range [−1,000..1,000]
    const bool in_boundary =
        std::none_of(A.cbegin(), A.cend(), [](const int e) { return e < MIN_ARRAY_ELEMENT && e > MAX_ARRAY_ELEMENT; });

    if (!in_boundary)
    {
        std::cout << "Array elements are not withing boundaries\n";
        return {};
    }

    // Cyclic rotation
    std::vector<int> result(A.size(), 0);
    int shift_index{0};
    int cycles_remainder = K % A.size();

    for (std::size_t i{0}; i < A.size(); ++i)
    {
        if ((i + cycles_remainder) >= A.size())
        {
            shift_index = cycles_remainder - (A.size() - i);
        }
        else
        {
            shift_index = cycles_remainder + i;
        }

        result.at(shift_index) = A[i];
    }

    for (const auto& e : result)
    {
        std::cout << e << "\n";
    }

    /* Codility solution */
    //    int n = A.size();
    //    vector<int> B(n, 0);
    //
    //    // Handle case of empty input array
    //    if (!n) {
    //        return B;
    //    }
    //
    //    int index = 0;
    //    if (K%n) {
    //        index = (n-K%n);
    //    }
    //
    //    // Copy elements from A to B, starting at the
    //    // calculated index
    //    for (int i=0; i<n; i++) {
    //        B[i] = A[index];
    //        index = ((index+1)%n);
    //    }

    return result;
}