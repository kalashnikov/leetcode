#include <iostream>
#include <vector>
#include <stack>
#include <list>

using namespace std;

// 12ms
// https://leetcode.com/discuss/37147/my-simple-8ms-c-code
int longestValidParentheses(string s) {
  stack<int> stk;
  stk.push(-1);
  int maxL=0;
  for(int i=0;i<s.size();i++)
  {
    int t=stk.top();
    if(t!=-1&&s[i]==')'&&s[t]=='(')
    {
      stk.pop();
      maxL=max(maxL,i-stk.top());
    }
    else
      stk.push(i);
  }
  return maxL;
}

// 20ms, Stack
int longestValidParentheses1(string s) {
  if(s.length()<2) return 0;

  list<int> stack; 
  vector<bool> bits(s.size(),false);
  for(int i=0;i<s.length();i++){
    if(s[i]==')'&&stack.empty()) continue;
    if(s[i]==')') { 
      bits[i] = bits[stack.back()] = true;
      stack.pop_back();
    } else {
      stack.push_back(i);
    }
  }
  
  cout << s << " | ";
  for(auto v:bits) cout << v << " "; cout << endl;

  int maxv = 0, ans = 0;
  for(int i=0;i<bits.size();i++) {
    if(!bits[i]) { 
      maxv = 0;
      continue;
    }
    ans = max(ans, ++maxv);
  }
  return ans; 
}

int main(){
  string s1 = ")()())";
  cout << longestValidParentheses(s1) << " 4" << endl;
  string s2 = ")()(())";
  cout << longestValidParentheses(s2) << " 6" << endl;
  string s3 = "()(()";
  cout << longestValidParentheses(s3) << " 2" << endl;
  string s4 = "(((()(";
  cout << longestValidParentheses(s4) << " 2" << endl;
  string s5 = "((()))())";
  cout << longestValidParentheses(s5) << " 8" << endl;
  string s6 = "(()()";
  cout << longestValidParentheses(s6) << " 4" << endl;
  string s7 = ")()())()()(";
  cout << longestValidParentheses(s7) << " 4" << endl;
  return 0;
}
