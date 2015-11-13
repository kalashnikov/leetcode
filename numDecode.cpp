#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

inline bool isAlpha(char a, char b) { 
  if ( a  > '2' ) return false;
  if ( a == '0' && b == '0' ) return false;
  if ( a == '2' && ( b == '0' || b > '6' ) ) return false; 
  return true;
}

int helper(vector<char> s, int cnt){
  if(s.size()==1) return (s[0]!='0') ? cnt : 0;
  if(s[0]!='0'){
    vector<char> ts(s.begin()+1,s.end());
    tmp1 = helper(ts, cnt);
  }
  if (isAlpha(s[0],s[1]) {
    if ( s.size()==2 ) return cnt+tcnt;
    vector<char> ts2(s.begin()+2,s.end());
    int tmp = helper(ts2, cnt);
    tcnt+=tmp;
  } 
  return tcnt;
}

int numDecodings2(string s) {
  if ( s.length()==0 ) return 0;
  if ( s.length()==1 ) return s[0]=='0' ? 0 : 1;
  if ( s.length()<2  ) return 1;
  int ans = 0, mul = 1;
  int i = 1;
  for(int i=1;i<s.length();i+=2){
    if(isAlpha(s[i-1],s[i])) 
      mul*=2; 
  }
  ans += mul; mul = 0;
  for(int i=2;i<s.length();i++) {
    if(isAlpha(s[i-1],s[i])) {  
      mul = mul==0 ? 1 : mul*2;
    }
  }
  ans += mul;
  return ans;
}

int numDecodings(string s) {
	if (!s.size() || s.front() == '0') return 0;
	// r2: decode ways of s[i-2] , r1: decode ways of s[i-1] 
	int r1 = 1, r2 = 1;

	for (int i = 1; i < s.size(); i++) {
		// zero voids ways of the last because zero cannot be used separately
		if (s[i] == '0') r1 = 0;

		// possible two-digit letter, so new r1 is sum of both while new r2 is the old r1
		if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6') {
			r1 = r2 + r1;
			r2 = r1 - r2;
		}

		// one-digit letter, no new way added
		else {
			r2 = r1;
		}
	}

	return r1;
}

int main(){
  cout << numDecodings("12") << endl;
  cout << numDecodings("121") << endl;
  cout << numDecodings("1212") << endl;
  cout << numDecodings("42") << endl;
  return 0;
}
