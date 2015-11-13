#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
  vector<int> ans;

  bool all9 = true; 
  for( auto v:digits ){ 
    if(v!=9) { 
      all9 = false;
      break; 
    }
  }
 
  if( all9 ) {
    ans.push_back(1);
    for(int i=0;i<digits.size();i++) ans.push_back(0);
  } else {
    int v = 0, carry = 1;
    for(int i=digits.size()-1;i>=0;i--){
      v = digits[i] + carry; 
      if (v==10) {
        digits[i]=0;
        carry=1;
      } else {
        digits[i] = v;
        break;
      }
    }
    ans = digits;
  }
  return ans;
}

int main(){

  vector<int> c1 { 2,9,9 } ; 
  auto a1 = plusOne(c1);
  for( auto v:a1) cout << v;
  cout << endl;

  vector<int> c2 { 9,9,9 } ; 
  auto a2 = plusOne(c2);
  for( auto v:a2) cout << v;
  cout << endl;

  return 0;
}
