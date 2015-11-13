#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

bool isAnagram(string s, string t) {
  if(s.length()!=t.length()) return false;
  unordered_map<char, int> d1, d2; 
  for(auto v:s) d1[v]++;
  for(auto v:t) d2[v]++;
  if(d1.size()!=d2.size()) return false;

  for(auto v:d1) {
    if(v.second!=d2[v.first]) 
      return false;
  }
  return true;
}

int main(){

  cout << isAnagram("anagram", "naagram") << endl;
  cout << isAnagram("car", "rat") << endl;

  return 0;
}
