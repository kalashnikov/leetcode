#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

bool isStrobogrammatic(string num) {
  if(num.length()==0) return true;
  string ret;
  for(int i=num.length()-1;i>=0;i--){
    if (num[i]!='0'&&num[i]!='1'&&num[i]!='6'&&
        num[i]!='9'&&num[i]!='8') 
      return false;
    if ( num[i]=='6' ) ret.push_back('9');
    else if ( num[i]=='9' ) ret.push_back('6');
    else ret.push_back(num[i]);
  }
  if ( num!=ret ) return false;
  return true;
}

int main(){
  cout << isStrobogrammatic("67") << endl;
  cout << isStrobogrammatic("69") << endl;
  cout << isStrobogrammatic("88") << endl;
  cout << isStrobogrammatic("818") << endl;
  return 0;
}
