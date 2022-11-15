/*
A small frog wants to get to the other side of the road. The frog is currently located at position X and wants to get to
a position greater than or equal to Y. The small frog always jumps a fixed distance, D.

Count the minimal number of jumps that the small frog must perform to reach its target.

    Write a function:

    int solution(int X, int Y, int D);

that, given three integers X, Y and D, returns the minimal number of jumps from position X to a position equal to or greater than Y.

For example, given:

  X = 10
  Y = 85
  D = 30
the function should return 3, because the frog will be positioned as follows:

after the first jump, at position 10 + 30 = 40
after the second jump, at position 10 + 30 + 30 = 70
after the third jump, at position 10 + 30 + 30 + 30 = 100
Write an efficient algorithm for the following assumptions:

X, Y and D are integers within the range [1..1,000,000,000];
X ≤ Y.
*/

#include <iostream>

bool isInRange(int value)
{
    constexpr int min_size{1};
    constexpr int max_size{1000000000};
    return (value >= min_size) && (value <= max_size);
}

/* Solution is optimal - perfect score! */
int frogJump(int X, int Y, int D)
{
    // Assumption: X, Y and D are integers within the range [1..1,000,000,000]
    if(!isInRange(X) || !isInRange(Y) || !isInRange(D))
    {
        //std::cout << "Value is out of range\n";
        return -1;
    }

    // Assumption: X ≤ Y
    if(X > Y)
    {
        //std::cout << "X is greater than Y\n";
        return -1;
    }

    int jumps = (Y - X) / D;

    if(((Y - X) % D) != 0 )
    {
        jumps += 1;
    }

    return jumps;
}