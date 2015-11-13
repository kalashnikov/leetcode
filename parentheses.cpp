#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

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

  return 0;
}
