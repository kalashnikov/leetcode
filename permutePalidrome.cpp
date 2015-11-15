#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool canPermutePalindrome(string s) {
  if(s.length()<2) return true;
  unordered_map<char, int> db;
  for(auto v:s){
    db[v]++;
  }
  int count1 = 0;
  for(auto v:db){
    if(v.second%2==1) 
      count1++;
    if(count1==2) 
      return false;
  }
  return true;
}

int main(){
  cout << canPermutePalindrome("code") << endl;
  cout << canPermutePalindrome("aab") << endl;
  cout << canPermutePalindrome("carerac") << endl;
  return 0;
}
