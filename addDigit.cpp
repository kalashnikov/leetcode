#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

int addDigits(int num) {
  // Digital root
  // http://www.wikiwand.com/en/Digital_root
  //
  // It helps to see the digital root of a positive integer as the position it holds with respect to the largest multiple of 9 less than it. 
  // For example, the digital root of 11 is 2, which means that 11 is the second number after 9. 
  // Likewise, the digital root of 2035 is 1, which means that 2035 − 1 is a multiple of 9. 
  // If a number produces a digital root of exactly 9, then the number is a multiple of 9.
  return (num-9*((num-1)/9));
}

int main(){
  cout << addDigits(29) << endl;
  cout << addDigits(38) << endl;
  cout << addDigits(65536) << endl;
  return 0;
}
