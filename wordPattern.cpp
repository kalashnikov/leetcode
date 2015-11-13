#include <iostream>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool wordPattern(string pattern, string str) {
  unordered_set<string> s;
  unordered_map<char, string> db; 

  int i=0, j=0, k;
  string tmps; 
  while(i<pattern.length()&&j<str.length()){
    k = 0;
    while(j+k+1<str.length() && str[j+k+1]!=' ') k++;
    tmps = str.substr(j, k+1);
    if(db.count(pattern[i])) { 
      if(db[pattern[i]]!=tmps)
        return false;
    } else {
      if(s.count(tmps)) return false;
      db[pattern[i]] = tmps;
      s.insert(tmps);
      //cout << pattern[i] << " -> " << tmps << endl;
    }
    i++; j += k+2;
    //cout << i << " " << j << endl;
  }
  if(i<pattern.length() || j<str.length()) return false;
  return true;
}

int main(){

  cout << wordPattern("abba", "dog cat cat dog") << endl;
  cout << wordPattern("abba", "dog cat cat fish") << endl;
  cout << wordPattern("aaaa", "dog cat cat dog") << endl;
  cout << wordPattern("abba", "dog dog dog dog") << endl;
  cout << wordPattern("aaa", "aa aa aa aa") << endl;

  return 0;
}
