#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "gtest/gtest.h"

using namespace std;

namespace 
{
  class ValidWordAbbr {
    unordered_map<string,unordered_set<string>> db; 
    public:
    ValidWordAbbr(vector<string> &dictionary) {
      for(const string& s : dictionary) 
        db[encode(s)].emplace(s);

      //cout << "Check: ";
      //for(auto v : db) {
      //  cout << v.first << ":"; 
      //  for(auto vv : v.second) 
      //    cout << vv << " ";
      //  cout << endl;
      //}
      //cout << endl;
    }

    bool isUnique(string word) {
      if(word.size()==0) return true;
      string s = encode(word);
      return !db.count(s) || ( db[s].size()==1 && db[s].count(word) ); 
    }

    string encode(string word) {
      if ( word.size()<3 ) return word; 
      return word.front() + to_string(word.size()-2) + word.back(); 
    }
  };
}


TEST(Test_1, TestAll) {
  vector<string> i1 {"deer", "door", "cake", "card", "it", "dog", "internationalization", "localization", "hello"};
  
  ValidWordAbbr vwa(i1);
  EXPECT_EQ(0, vwa.isUnique("dear")  );
  EXPECT_EQ(1, vwa.isUnique("cart")  );
  EXPECT_EQ(0, vwa.isUnique("cane")  );
  EXPECT_EQ(1, vwa.isUnique("make")  );
  EXPECT_EQ(1, vwa.isUnique("hello") );
}

//int main(){
//  vector<string> i1 {"deer", "door", "cake", "card", "it", "dog", "internationalization", "localization", "hello"};
//  
//  ValidWordAbbr vwa(i1);
//  cout << vwa.isUnique("dear")  << " 0" << endl;
//  cout << vwa.isUnique("cart")  << " 1" << endl;
//  cout << vwa.isUnique("cane")  << " 0" << endl;
//  cout << vwa.isUnique("make")  << " 1" << endl;
//  cout << vwa.isUnique("hello") << " 1" << endl;
//
//  return 0;
//}
