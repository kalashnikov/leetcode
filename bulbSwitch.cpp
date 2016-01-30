#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include "gtest/gtest.h"

using namespace std;

namespace 
{
  // http://stackoverflow.com/questions/295579/fastest-way-to-determine-if-an-integers-square-root-is-an-integer
  bool isPerfectSquare(int n)
  {
    int h = n & 0xF;  // h is the last hex "digit"
    if (h > 9)
      return false;
    // Use lazy evaluation to jump out of the if statement as soon as possible
    if (h != 2 && h != 3 && h != 5 && h != 6 && h != 7 && h != 8)
    {
      int t = (int) floor( sqrt((double) n) + 0.5 );
      return t*t == n;
    }
    return false;
  }

  int bulbSwitch(int n) {
    if ( n < 2 ) return n; 

    // Brute-force
    //int ret = 1, tmp; 
    //for(int i=2;i<=n;i++)
    //  if( isPerfectSquare(i) )
    //    ret++;
    //return ret;

    return sqrt(n);
  }
}

TEST(Test_1, TestAll) {
  EXPECT_EQ(1, bulbSwitch(3) );
}

TEST(Test_2, TestAll) {
  EXPECT_EQ(2, bulbSwitch(5) );
}

TEST(Test_big, TestAll) {
  EXPECT_EQ(10000, bulbSwitch(100000000) );
}
