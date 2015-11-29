#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

int longestValidParentheses(string s) {
  if(s.length()<2) return 0;
  int i = 0, n = s.length();
  int cnt = 0, maxv = 0, ans = 0, tot = 0;
  while(i<n){
    //cout << i << " | " << maxv << endl;
    while(i<n  && s[i]==')') { 
      maxv = 0;
      i++;
    }
    if(s[i]=='(') { 
      i++; maxv++; cnt = 1; tot = 0;
      while(i<n && cnt!=0){
        if(s[i]=='(') {
          cnt++; 
        } else { 
          cnt--;
          tot++;
        }
        maxv++;
        //cout << "# " << cnt << " | " << maxv << endl;
        i++;
      }
      if(cnt==0) { 
        ans = max(ans, maxv);
      } else { 
        ans = max(ans, tot*2);
        maxv = 0; 
      }
    }
  }
  return ans; 
}

int main(){
  string s1 = ")()())";
  cout << longestValidParentheses(s1) << " 4" << endl;
  string s2 = ")()(())";
  cout << longestValidParentheses(s2) << " 6" << endl;
  string s3 = ")(";
  cout << longestValidParentheses(s3) << " 0" << endl;
  string s4 = "(((()(";
  cout << longestValidParentheses(s4) << " 2" << endl;
  return 0;
}
