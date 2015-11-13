#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
  if ( strs.size() == 0 ) return "";
  if ( strs.size() == 1 ) return strs[0];

  int i = 1, lim = 0;
  while(1){
    for(i=1;i<strs.size();i++){
      if(strs[i][lim]=='\0'||strs[i][lim]!=strs[0][lim]) 
        break;
    }
    if ( i!=strs.size() ) break;
    lim++; 
  }

  return strs[0].substr(0, lim);
}

int main(){


  vector<string> s0 { "ab", "ba" };
  cout << longestCommonPrefix(s0) << endl;
  vector<string> s1 { "aba", "abas", "abad"};
  cout << longestCommonPrefix(s1) << endl;
  return 0;
}
