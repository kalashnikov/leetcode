#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <list>

using namespace std;

// 8ms 
// https://leetcode.com/discuss/33854/my-6-lines-solution
bool isIsomorphic(string s, string t) {
  if(s.length()!=t.length()) return false;
  int m1[256] = {0}, m2[256] = {0}, n = s.size();
  for (int i = 0; i < n; ++i) {
    if (m1[s[i]] != m2[t[i]]) return false; // ex: "ab" to "aa"
    m1[s[i]] = i + 1;
    m2[t[i]] = i + 1;
  }
  return true;
}

// 44 ms
bool isIsomorphic(string s, string t) {
  if(s.length()!=t.length()) return false;
  unordered_set<char> d;
  unordered_map<char, char> m;

  int i = 0, j = 0;
  while(i<s.length()){
    if(m.count(s[i])) { 
      if (t[j]!=m[s[i]])  return false;
    } else {
      if (d.count(t[j]))  return false; 
    }
    m[s[i]] = t[j];
    d.insert(t[j]);
    i++,j++;
  }
  return true;
}

int main(){
  cout << isIsomorphic("ab", "aa") << endl;

  cout << isIsomorphic("egg", "add") << endl;

  cout << isIsomorphic("foo", "bar") << endl;

  cout << isIsomorphic("paper", "title") << endl;

  return 0;
}
