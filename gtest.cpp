#include <algorithm>
#include "gtest/gtest.h"

namespace 
{
  int GCD(int a, int b) {
    int d = 1;
    for (int i = 2; i <= std::min(a, b); ++i)  {
      if (0 == a % i && 0 == b % i) {
        d = i;
      }
    }
    return d;
  }
}

TEST(TestGCD_1, TestAll) {
  EXPECT_EQ(5, GCD(10, 15));
  EXPECT_EQ(5, GCD(15, 10));
  EXPECT_EQ(1, GCD(3, 5));
  EXPECT_EQ(5, GCD(5, 15));
  EXPECT_EQ(6, GCD(18, 24));
}


//int main(int argc, char *argv[])
//{
//  testing::InitGoogleTest(&argc, argv);
//  return RUN_ALL_TESTS();
//}
