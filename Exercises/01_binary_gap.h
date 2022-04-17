/*
A binary gap within a positive integer N is any maximal sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N.

For example, number 9 has binary representation 1001 and contains a binary gap of length 2. The number 529 has binary representation 1000010001 and contains two binary gaps: one of length 4 and one of length 3. The number 20 has binary representation 10100 and contains one binary gap of length 1. The number 15 has binary representation 1111 and has no binary gaps. The number 32 has binary representation 100000 and has no binary gaps.

Write a function:

int solution(int N);

that, given a positive integer N, returns the length of its longest binary gap. The function should return 0 if N doesn't contain a binary gap.

For example, given N = 1041 the function should return 5, because N has binary representation 10000010001 and so its longest binary gap is of length 5. Given N = 32 the function should return 0, because N has binary representation '100000' and thus no binary gaps.

Write an efficient algorithm for the following assumptions:

N is an integer within the range [1..2,147,483,647].

*/

#include <vector>
#include <iostream>

int binaryGap(int N) {
  if(N < 0)
  {
    std::cout << "Passed number is negative! Aborting...";
    return -1;
  }

  std::vector<bool> result_vector;

  // Convert to binary
  while(N != 0)
  {
    result_vector.emplace_back(N % 2);
    N/= 2;
  }

  // Check for gaps
  int max_number_of_gaps{0};
  int number_of_gaps{0};
  int i{static_cast<int>(result_vector.size() - 1)};
  bool opening_one{false};
  bool closing_one{false};

  while(i != -1)
  {
    // Check if we encountered a gap beginning
    if((result_vector[i] == 0) && (result_vector[i+1]) && (!opening_one))
    {
      opening_one = true;
    }

    // Check if we encountered a gap ending
    if(opening_one && (result_vector[i] == 1))
    {
      closing_one = true;
    }
    
    if(opening_one && (!closing_one)) 
    {
      ++number_of_gaps;
    }

    // If we encircled a gap, set the highest gap value and reset
    if(opening_one && closing_one)
    {
      if(number_of_gaps > max_number_of_gaps)
      {
        max_number_of_gaps = number_of_gaps;
      }

      number_of_gaps = 0;
      opening_one = false;
      closing_one = false;
    }
    
    --i;
  }

  return max_number_of_gaps;
}