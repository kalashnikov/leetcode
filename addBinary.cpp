#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

// https://leetcode.com/discuss/25593/short-code-by-c
string addBinary(string a, string b)
{
  string s = "";

  int c = 0, i = a.size() - 1, j = b.size() - 1;
  while(i >= 0 || j >= 0 || c == 1)
  {
    c += i >= 0 ? a[i --] - '0' : 0;
    c += j >= 0 ? b[j --] - '0' : 0;
    s = char(c % 2 + '0') + s;
    c /= 2;
  }

  return s;
}

// 4ms
string addBinary2(string a, string b) {
  if ( a.length()==0 && b.length()==0 ) return "";
  if ( a.length()==0 ) return b;
  if ( b.length()==0 ) return a;

  bool debug = false;
  int idx = 0;
  int max =  a.length()>b.length() ? (a.length()+1) : (b.length()+1);
  vector<bool> ans(max,0);

  int i = a.length()-1;
  int j = b.length()-1;
  bool carry = false;

  if ( a.length() < b.length() ) { 
    while(j>=0){
      ans[idx++] = b[j--]=='1'?true:false; 
    }
    idx = 0;
    if ( debug ) { cout << "1a: "; for(auto v:ans) cout << v; cout << endl; }
    while(i>=0){
      int t = 0; 
      if(carry) t++;
      if(a[i--]=='1') t++;
      if(ans[idx]) t++;
      if(t>1) carry = true;
      else carry = false;
      ans[idx++] = t%2;
    }
  } else { 
    while(i>=0){
      ans[idx++] = a[i--]=='1'?true:false; 
    }
    idx = 0;
    if ( debug ) { cout << "1b: "; for(auto v:ans) cout << v; cout << endl; }
    while(j>=0){
      int t = 0; 
      if(carry) t++;
      if(b[j--]=='1') t++;
      if(ans[idx]) t++;
      if ( debug ) cout << idx << " " << t << endl;
      if(t>1) carry = true;
      else carry = false;
      ans[idx++] = t%2;
    }
  }
  
  if ( debug ) { cout << "2:  ";for(auto v:ans) cout << v; cout << endl; }
 
  while(carry) { 
    int t = 0; 
    if(carry) t++;
    if(ans[idx]) t++;
    if(t>1) carry = true;
    else carry = false;
    ans[idx++] = t%2;
  }
  if ( debug ) { cout << "3:  ";for(auto v:ans) cout << v; cout << endl; } 
 
  stringstream ss;
  i = ans[ans.size()-1] ? ans.size()-1 : ans.size()-2;
  for(;i>=0;i--) { 
    if(ans[i])
      ss << 1;
    else 
      ss << 0;
  }
  return ss.str();
}

int main(){
  cout << addBinary("111","101") << endl;
  cout << addBinary("0","0") << endl;
  cout << addBinary("1010","1011") << endl;
  return 0;
}
