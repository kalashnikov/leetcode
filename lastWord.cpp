#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

int lengthOfLastWord(string s) {
  int cnt = 0, len = s.length()-1;
  while(len>=0){
    if(s[len]!=' '&&isalpha(s[len]))  cnt++;
    else if(cnt!=0&&s[len]==' ')      break;
    len--; 
  }
  return cnt;
}

int main(){
  cout << lengthOfLastWord("") << endl;
  cout << lengthOfLastWord("adg idb") << endl;
  cout << lengthOfLastWord("sdbd") << endl; 
  cout << lengthOfLastWord(" abda") << endl; 
  cout << lengthOfLastWord(" abd, ") << endl; 
  return 0;
}
