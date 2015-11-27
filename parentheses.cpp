#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

// DP version
// https://leetcode.com/discuss/11509/an-iterative-method
// Actually it's Catalan number
// https://www.wikiwand.com/en/Catalan_number

// using pass by reference: 0ms
// using pass by value: 2ms
void helper(vector<string>& ans, string& cur, int cand1, int cand2){
  if (cand1==0) { // all end parentheses left
    for(int i=0;i<cand2;i++) cur.push_back(')'); 
    ans.push_back(string(cur.begin(),cur.end()));
    for(int i=0;i<cand2;i++) cur.pop_back(); 
  } else if (cand2==0) {
    cur.push_back('(');
    cand1--, cand2++;
    helper(ans, cur, cand1, cand2); 
    cur.pop_back();
  } else {
    cur.push_back('(');
    helper(ans, cur, cand1-1, cand2+1);
    cur.pop_back();
    cur.push_back(')');
    helper(ans, cur, cand1, cand2-1);
    cur.pop_back();
  }
}

vector<string> generateParenthesis(int n) {
  if(n==0) return vector<string>();
  if(n==1) return vector<string>{"()"};
  string cur;
  vector<string> ans; 
  int cand1 = n, cand2 = 0;
  helper(ans, cur, cand1, cand2);
  return ans;
}

bool isValid(string s) {
  list<char> l;
  for(auto v:s){
    if(v=='[' || v=='{' || v=='(')
      l.push_back(v);
    else {
      if ( ( v==']' && l.back()=='[' ) || 
           ( v=='}' && l.back()=='{' ) ||
           ( v==')' && l.back()=='(' ) ){ 
        l.pop_back();
      } else { 
        return false;
      }
    }
  }
  if(!l.empty()) return false; 
  return true;
}

int main(){

  cout << isValid("[") << endl;
  cout << isValid("()[]{}") << endl;
  cout << isValid("[{]}") << endl;

  auto a1 = generateParenthesis(3);
  for(auto v:a1) cout << v << " "; cout << endl;

  // Catalan_number 
  // ans[i] = (4*i-2)*ans[i-1]/(i+1);
  cout << generateParenthesis(2).size() << endl;
  cout << generateParenthesis(3).size() << endl;
  cout << generateParenthesis(4).size() << endl;
  cout << generateParenthesis(5).size() << endl;
  return 0;
}
