#include <iostream>
using namespace std;

int main() {
  unsigned int a = 60;	  // 60 = 0011 1100
  unsigned int b = 13;	  // 13 = 0000 1101
  int c = 0;

  c = a & b;             // 12 = 0000 1100 => AND
  cout << "Line 1 - Value of c is : " << c << endl ;

  c = a | b;             // 61 = 0011 1101 => OR
  cout << "Line 2 - Value of c is: " << c << endl ;

  c = a ^ b;             // 49 = 0011 0001 => XOR
  cout << "Line 3 - Value of c is: " << c << endl ;

  c = ~a;                // -61 = 1100 0011 => NOT
  cout << "Line 4 - Value of c is: " << c << endl ;

  c = a << 2;            // 240 = 1111 0000 => Bitwise shift left
  cout << "Line 5 - Value of c is: " << c << endl ;

  c = a >> 2;            // 15 = 0000 1111 => Bitwise shift right
  cout << "Line 6 - Value of c is: " << c << endl ;

  return 0;
}