#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

// I 1
// V 5
// X 10
// L 50
// C 100
// D 500
// M 1,000
//
// I, II, III, IV, V, VI, VII, VIII, IX, X.
int romanToInt(string s) {
  bool sub = false;
  int ans = 0, val = 0;
  for(int i=0;i<s.length();i++){
    sub = false;

    // Addition 
    if ( s[i]=='V' ) { ans += 5; continue; }
    else if ( s[i]=='L' ) { ans += 50; continue; }
    else if ( s[i]=='D' ) { ans += 500; continue; }
    else if ( s[i]=='M' ) { ans += 1000; continue; }

    // Maybe addition/subtration 
    if ( s[i]=='I' && i!=s.length()-1 && (s[i+1]=='V'||s[i+1]=='X') ) sub = true;
    else if ( s[i]=='X' && i!=s.length()-1 && (s[i+1]=='L'||s[i+1]=='C') ) sub = true;
    else if ( s[i]=='C' && i!=s.length()-1 && (s[i+1]=='D'||s[i+1]=='M') ) sub = true;
    switch (s[i]){
      case 'I' : 
        val = 1;break;
      case 'X' : 
        val = 10;break;
      case 'C' : 
        val = 100;break;
      default: 
        cout << "ERRROR. " << s[i] << endl;
    }
    ans += ( (sub) ? -val : val );
  }
  return ans;
}

int main(){
  cout << romanToInt("VII") << " " << 7 << endl;
  cout << romanToInt("MCMIV") << " " << 1904 << endl;
  cout << romanToInt("MCMLIV") << " " << 1954<< endl;
  cout << romanToInt("MCMXC") << " " << 1990 << endl;
  cout << romanToInt("MMXIV") << " " << 2014 << endl;
  return 0;
}
