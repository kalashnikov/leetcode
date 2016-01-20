#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include "gtest/gtest.h"

using namespace std;

namespace{

  static bool cmp(const string& a, const string& b){
    return a.size() > b.size();
  }

  int maxProduct(vector<string>& words) {
    if( words.size()==0 ) return 0;
    
    int bits[words.size()]; 
    memset(bits, 0, sizeof(bits));
    
    sort(words.begin(),words.end(), cmp);

    for(unsigned int i=0;i<words.size();i++) 
      for(const char& c : words[i]) 
        bits[i] |= 1 << (c-'a');
    
    unsigned long ans = 0, size = words.size();
    for(unsigned int i=0;i<size-1;i++) { 
      int si = words[i].size();
      if( si*si <= ans ) break;
      for(unsigned int j=i+1;j<size;j++) {
        int sj = words[j].size();
        if( si*sj <= ans ) break;
        if( ( bits[i] & bits[j] ) == 0 ){
          ans = max(ans, (unsigned long)si*sj);
        }
      }
    }
    return ans;
  }
}

TEST(DemoTest, TestAll) {
  vector<string> iv { "abcw", "baz", "foo", "bar", "xtfn", "abcdef" }; 
  EXPECT_EQ(16, maxProduct(iv) );
}

TEST(DemoTest2, TestAll) {
  vector<string> iv { "a", "ab", "abc", "d", "cd", "bcd", "abcd" }; 
  EXPECT_EQ(4, maxProduct(iv) );
}

TEST(DemoTest3, TestAll) {
  vector<string> iv { "a", "aa", "aaa", "aaaa"}; 
  EXPECT_EQ(0, maxProduct(iv) );
}

TEST(DemoTest4, TestAll) {
  vector<string> iv { "a","ab","abc","abcd","abcde","abcdef","abcdefg","abcdefgh","abcdefghi","abcdefghij","abcdefghijk","abcdefghijkl","abcdefghijklm","nopqrstuvwxyz","mnopqrstuvwxyz","lmnopqrstuvwxyz","klmnopqrstuvwxyz","jklmnopqrstuvwxyz","ijklmnopqrstuvwxyz","hijklmnopqrstuvwxyz","ghijklmnopqrstuvwxyz","fghijklmnopqrstuvwxyz","efghijklmnopqrstuvwxyz","defghijklmnopqrstuvwxyz","cdefghijklmnopqrstuvwxyz","bcdefghijklmnopqrstuvwxyz" }; 
  EXPECT_EQ(169, maxProduct(iv) );
}
