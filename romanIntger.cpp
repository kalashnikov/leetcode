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

// https://leetcode.com/discuss/32626/simple-solution
string intToRoman(int num) { 
  string M[] = {"", "M", "MM", "MMM"};
  string C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
  string X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
  string I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
  return M[num/1000] + C[(num%1000)/100] + X[(num%100)/10] + I[num%10];
}

// 28 ms 
string intToRoman2(int num) {

  string ans = "";
  while(num>=1000){ ans +=  "M"; num-=1000; }
  if (num>=100){
    if (num>= 900){ ans += "CM"; num-= 900; }
    else if (num>= 500){ ans += "D"; num-= 500; }
    else if (num>= 400){ ans += "CD"; num-= 400; }

    while(num>=100) { ans += "C"; num-= 100; }
  }
  if (num>=10){
    if (num>= 90){ ans += "XC"; num-= 90; }
    else if (num>= 50){ ans += "L"; num-= 50; }
    else if (num>= 40){ ans += "XL"; num-= 40; }

    while(num>=10) { ans += "X"; num-= 10; }
  }

  if (num>= 9){ ans += "IX"; num-= 9; }
  else if (num>= 5){ ans += "V"; num-= 5; }
  else if (num>= 4){ ans += "IV"; num-= 4; }

  while(num) { ans += "I"; num-= 1; }
  return ans;
}

int main(){
  cout << romanToInt("VII") << " " << 7 << endl;
  cout << romanToInt("MCMIV") << " " << 1904 << endl;
  cout << romanToInt("MCMLIV") << " " << 1954<< endl;
  cout << romanToInt("MCMXC") << " " << 1990 << endl;
  cout << romanToInt("MMXIV") << " " << 2014 << endl;

  cout << intToRoman(7)    << " VII"   << endl;
  cout << intToRoman(1904) << " MCMIV" << endl;
  cout << intToRoman(1954) << " MCMLIV"<< endl;
  cout << intToRoman(1990) << " MCMXC" << endl;
  cout << intToRoman(2014) << " MMXIV" << endl;
  cout << intToRoman(3999) << " " << romanToInt("MMMCMXCIX") << endl;
  return 0;
}
