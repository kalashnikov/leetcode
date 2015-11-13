#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

// 1, 11, 21, 1211, 111221, ...
string countAndSay(int n) {
  if (n==0) return "";
  static unordered_map<int, string> cache;
  cache[1] = "1";
  if (cache.count(n)) return cache[n];

  int i, j = 1, cnt;
  string num = "1";
  while(j<n){
    i = 0;
    stringstream ss;
    while(num[i]!='\0'){
      cnt = 1;
      while(num[i+1]==num[i]) { i++; cnt++;}
      ss << cnt << num[i]; 
      i++;
    }
    num = ss.str(); 
    cache[j] = num;
    j++;
  }
  cache[n] = num;
  return num;
}

int main(){
  cout << countAndSay(5) << endl; 
  cout << countAndSay(3) << endl; 
  cout << countAndSay(1) << endl; 
  return 0;
}
