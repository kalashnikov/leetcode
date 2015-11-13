#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

void reverseWords(string &s) {
  if(s.length()<2) return; 
  int i = 0, j = s.length()-1;
  while(i<j) swap(s[i++],s[j--]);
  int last = 0;
  for(int n=1;n<s.length();n++){
    if(s[n]==' '){
      i=last, j=n-1;
      while(i<j) swap(s[i++],s[j--]);
      last = n+1;
    }
  }
  // Last word
  i=last, j=s.length()-1;
  while(i<j) swap(s[i++],s[j--]);
  return;
}

int main(){
  string s1 = "the sky is blue";
  reverseWords(s1);
  cout << s1 << endl;
  return 0;
}
