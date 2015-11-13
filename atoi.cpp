#include <iostream>

using namespace std;

int myAtoi(string str) {
  if(str.length()==0) return 0;
  if(str.length()==1 && str[0]>'0' && str[0]<'9') return (str[0]-'0');
  long ans = 0;
  bool neg = false, pos = false, hasNum = false; 
  for(int i=0;i<str.length();i++){
    if(str[i]==' ') { if ( !hasNum ) continue; else break; }
    if(str[i]=='-' || str[i]=='+' ) {
      if ( pos || neg ) break;
      if ( str[i]=='-' ) neg = true;
      if ( str[i]=='+' ) pos = true;
      hasNum = true;
      continue; 
    } 
    if(str[i]>'9' || str[i]<'0') break;
    hasNum = true;
    ans = ans*10 + (str[i]-'0');
    if ( ans > INT_MAX ) break;
  }
  if ( !neg ) { 
    ans = min(ans, (long)INT_MAX);
  } else { 
    ans = min(ans, (long)INT_MAX+1);
  }
  return neg ? -ans : ans;
}

int main(){

  cout << myAtoi("") << endl;
  cout << myAtoi("010") << endl;
  cout << myAtoi("   010") << endl;
  cout << myAtoi("   +0 10") << endl;
  cout << myAtoi("+23") << endl;
  cout << myAtoi("+013") << endl;
  cout << myAtoi("-52") << endl;
  cout << myAtoi("-072") << endl;
  cout << myAtoi("+2.3") << endl;
  cout << myAtoi("abs") << endl;
  cout << myAtoi("+-2") << endl;
  cout << myAtoi("-+2") << endl;
  cout << myAtoi(" ++2") << endl;
  cout << myAtoi("  - 2") << endl;
  cout << myAtoi("2147483648") << endl;
  cout << myAtoi("214748364811") << endl;
  cout << myAtoi("-2147483648") << endl;
  return 0;
}
