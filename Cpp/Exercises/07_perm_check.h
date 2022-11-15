#include <set>
#include <vector>

/* *
 * Solution only checks for missing numbers in vector, but not for repeating values!
 * Lessons learned - read the problem description more carefully!
 * */
int permCheck(std::vector<int>& A)
{
    std::set<int> results;

    for (const auto& e : A)
    {
        results.emplace(e);
    }

    int result{0};

    for (auto it = results.begin(); it != results.end(); ++it)
    {
        if(std::next(it) != results.end())
        {
            result = *std::next(it) - *it;
            if (result != 1)
            {
                return false;
            }
        }
    }

    return true;

    /* Codility solution */
//    unsigned int N = A.size();
//
//    std::vector<int> track(N, 0);
//    unsigned int n = 0;
//
//    // go through and look at elements of A.  If A[i] > N then there
//    // is a number missing.  Otherwise sum up all of the numbers,
//    // make sure there are no duplicates
//    for (unsigned int i = 0; i < N; i++)
//    {
//        if (((unsigned int)A[i]) > N)
//        {
//            return 0;
//            // A[i] is larger than N so there is a number missing
//        }
//        else if (track[A[i] - 1])
//        {
//            // We already found this element, must be a duplicate
//            // Not a permutation
//            return 0;
//        }
//        else
//        {
//            // Increments number of elements we found, notes specific number
//            n++;
//            track[A[i] - 1] = 1;
//        }
//    }
//
//    // Not a permutation if we didn't get N unique elements
//    if (n != N)
//    {
//        return 0;
//    }
//
//    return 1;
}
