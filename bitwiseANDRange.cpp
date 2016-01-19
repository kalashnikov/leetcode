#include <iostream>
#include "gtest/gtest.h"

using namespace std;

namespace 
{
  // 64ms
  // https://leetcode.com/discuss/34918/one-line-c-solution
  int rangeBitwiseAnd(int m, int n) {
    int trans = 0;
    while(m != n) 
    {
      ++ trans;
      m >>= 1;
      n >>= 1;
    }
    return m << trans;
  }

  // 72 ms 
  // https://leetcode.com/discuss/49088/2-line-solution-with-detailed-explanation 
  int rangeBitwiseAnd(int m, int n) {
    while(m<n) n = n & (n-1);
    return n;
  }

  // 84 ms
  /*
  int roundPower2minus1(int n){
    n--;
    n |= n >> 1;
    n |= n >> 2;
    n |= n >> 4;
    n |= n >> 8;
    n |= n >>16;
    // n++;
    return n;
  }

  int rangeBitwiseAnd(int m, int n) {
    if ( (m&n)==0 ) return 0;
    if ( m==0 || m==n ) return m; 
    int d = roundPower2minus1(n-m+1); 
    //cout << d << " " << (n&d) << endl;
    return m & ( n - ( n & d ) );
  }
  */
}

TEST(Test_1, TestAll) {
  EXPECT_EQ(0, rangeBitwiseAnd(3,5) );
  EXPECT_EQ(0, rangeBitwiseAnd(3,7) );
  EXPECT_EQ(4, rangeBitwiseAnd(4,7) );
  EXPECT_EQ(4, rangeBitwiseAnd(5,7) );
  EXPECT_EQ(7, rangeBitwiseAnd(7,7) );
  EXPECT_EQ(0, rangeBitwiseAnd(6,8) );
  EXPECT_EQ(0, rangeBitwiseAnd(7,8) );
}
