#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include "gtest/gtest.h"

using namespace std;

namespace 
{
  int maxSubArrayLen(vector<int>& nums, int k) {
    if ( nums.empty() ) return 0;

    int ret = 0, st=nums.size(); 
    unordered_map<int, int> db;
    db.reserve(st);

    long cur = nums[0];
    db.emplace(nums[0], 0);
    for(int i=1;i<st;i++) {
      cur += nums[i];
      if ( db.count(cur) )  
        db[cur] = min(db[cur], i);
      else 
        db[cur] = i;
      
      if ( cur==k ) ret = max(ret, i+1);
      if ( db.count(cur-k) )
          ret = max(ret, i-db[cur-k]);
    }

    if ( ret == 0 ) 
      for(const int& v:nums) 
        if(v==k) 
          return 1;

    return ret;
  }
}

TEST(Test_1, TestAll) {
  vector<int> i1 { 1, -1, 5, -2, 3 };
  EXPECT_EQ(4, maxSubArrayLen(i1, 3) );
}

TEST(Test_2, TestAll) {
  vector<int> i1 { -2, -1, 2, 1 };
  EXPECT_EQ(2, maxSubArrayLen(i1, 1) );
}

TEST(Test_3, TestAll) {
  vector<int> i1 { -1, 1 };
  EXPECT_EQ(2, maxSubArrayLen(i1, 0) );
}

TEST(Test_MIN, TestAll) {
  vector<int> i1 { -1 };
  EXPECT_EQ(1, maxSubArrayLen(i1, -1) );
}

TEST(Test_4, TestAll) {
  vector<int> i1 { -5,8,2,-1,6,-3,7,1,8,-2,7 };
  EXPECT_EQ(0, maxSubArrayLen(i1, -4) );
}
