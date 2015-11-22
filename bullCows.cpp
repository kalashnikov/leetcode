#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

// Using counter 
// https://leetcode.com/discuss/69430/4-ms-c-using-counters
// 4ms 
string getHint(string secret, string guess) {
  int countS[10], countG[10];
  fill_n(countS,10,0);
  fill_n(countG,10,0);

  int i, len=guess.size(), ACnt=0, BCnt=0;
  for(i=0; i<len;++i)
  {
    if(guess[i]==secret[i]) ++ACnt;
    else
    {
      ++countG[guess[i] -'0'];
      ++countS[secret[i]-'0'];
    }
  }
  for(i=0;i<10;++i)
    BCnt += min(countS[i], countG[i]);

  return to_string(ACnt) + 'A'+ to_string(BCnt) + 'B';    
}

// 20ms
string getHint2(string secret, string guess) {

  unordered_map<char,int> s;
  int acnt = 0, bcnt = 0;
  
  // A scanning 
  for(int i=0;i<secret.length();i++){
    if(secret[i]==guess[i]) { 
      guess[i]  = 'Z';
      secret[i] = 'Z';
      acnt++;
    } else {
      s[secret[i]]++;
    }
  }

  // B scanning
  for(int i=0;i<guess.length();i++){
    if(guess[i]!='Z' && s.count(guess[i]) && s[guess[i]]>0) { 
      s[guess[i]]--; 
      bcnt++;
    }
  }

  return string(to_string(acnt) + "A" + to_string(bcnt) + "B");
}

int main(){
  cout << getHint("1807", "7810") << endl; // 1A3B 
  cout << getHint("1123", "0111") << endl; // 1A1B
  cout << getHint("00112233445566778899", "16872590340158679432") << endl; // 3A17B
  return 0;
}
