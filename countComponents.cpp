#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include "gtest/gtest.h"

using namespace std;
namespace 
{
  int countComponents(int n, vector<pair<int, int>>& edges) {
    int groupCnt = n, group1 = 0, group2 = 0;
    
    // Group table
    vector<int> group(n,0); 
    for(int i=0;i<n;i++) group[i] = i;

    for(const pair<int,int>& p : edges){
      if ( group[p.first] == group[p.second] )  continue;
      
      group1 = group[p.first];
      group2 = group[p.second];
      if( group1 > group2 ) swap(group1, group2);

      // Two edge have different grouop 
      for(int i=0;i<n;i++){
        // Change all second group to the first one
        if ( group[i]==group2 ) {
          group[i]=group1;
        }
      }
      groupCnt--;

      //for(auto v: group) cout << v << " "; cout << endl;
    }

    return groupCnt;
  }
}

TEST(DemoTest, TestAll) {
  vector<pair<int,int>> iv { {0,1}, {1,2}, {3,4} }; 
  EXPECT_EQ(2, countComponents(5, iv) );
}

TEST(MergeTest, TestAll) {
  vector<pair<int,int>> iv { {0,1}, {1,2}, {2,3}, {3,4} }; 
  EXPECT_EQ(1, countComponents(5, iv) );
}

TEST(EmptyTest, TestAll) {
  vector<pair<int,int>> iv; 
  EXPECT_EQ(2, countComponents(2, iv) );
}
