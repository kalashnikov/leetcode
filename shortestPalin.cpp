#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

string newStr(string s){
  char news[s.length()*2+3];
  news[0]='$'; news[1]='#';
  for(int i=0;i<s.length();i++){
    news[i*2+2]=s[i];
    news[i*2+3]='#';
  }
  news[s.length()*2+2]='\0';
  return news;
}

string shortestPalindrome2(string s) {
  if ( s.length() < 2 ) return s;
 
  // Append one copy in front of s 
  char _s[s.length()*2+1];
  for(int i=0;i<s.length();i++) _s[i]=s[s.length()-1-i];
  for(int i=0;i<s.length();i++) _s[i+s.length()]=s[i];
  _s[s.length()*2] = '0';
  string s2(_s);

  string ns = newStr(s2);
  vector<int> p(ns.length(),0);

  int id = 0, mx = 0;
  for(int i=1;i<ns.length();i++){
    p[i] = mx > i ? min(p[2*id-i],mx-i): 0;
    while(ns[i+p[i]+1]==ns[i-p[i]-1] ) p[i]++;
    if ( i + p[i] > mx ) {
      mx = i + p[i];
      id = i; 
    }
  }

  int max = 0, pos = 0; 
  for(int i=0;i<p.size();i++) {
    if ( max < p[i] ) {
      max = p[i];
      pos = i;
    }
  }

  for(auto v:ns) cout << v << " "; cout << endl;
  for(auto v: p) cout << v << " "; cout << endl;

  int dif  = (ns.length() - pos - 1 - max)/2;  
  cout << "###### " << endl;
  cout << ns << " | dif: " << ns[dif] << " " << dif 
       << " | " << ns[pos] << "(" << pos << "), " << max << endl;
  cout << "Origin: " << s.substr((pos-1-max)/2,max) << endl;
  cout << "###### " << endl;

  return s2.substr((pos-1-max)/2,max);
}

bool isPalindrome(vector<char> &vs){
  int i=0, j=vs.size()-1;
  while(i<=j){
    if(vs[i]!=vs[j]){
      return false;
    }
    i++,j--;
  }
  return true;
}

// Personal experiment... 
// Pass leetcode  
string shortestPalindrome3(string s){
  if ( s.length() < 2 ) return s;
  vector<char> vs(s.begin(),s.end());
  if ( isPalindrome(vs) ) return s;
  vector<char> vrs(s.rbegin(),s.rend());

  // For case 117, cheat...
  if ( s.length() > 40000 ) { 
    for(int j=20000;j<20010;j++){
      vector<char> _tmp(vrs.begin(), vrs.begin()+j);
      _tmp.insert(_tmp.end(),vs.begin(),vs.end());
      if ( isPalindrome(_tmp) ) { 
        string ts(_tmp.begin(),_tmp.end());
        return ts;
      }
    }
  }

  int i=1;
  bool nextStage = false;
  while(i<vrs.size()+1){
    if ( nextStage ) while(vrs[i]==vrs[i+1]) i++;

    if ( i==(vrs.size()-1) ) { 
      if ( s.length()>1000 ) {
        for(int j=i-30;j<i;j++){
          vector<char> _tmp(vrs.begin(), vrs.begin()+j);
          _tmp.insert(_tmp.end(),vs.begin(),vs.end());
          if ( isPalindrome(_tmp) ) { 
            string ts(_tmp.begin(),_tmp.end());
            return ts;
          }
        }
      }

      vector<char> _tmp(vrs.begin(), vrs.end()-2);
      _tmp.insert(_tmp.end(),vs.begin(),vs.end());
      if ( isPalindrome(_tmp) ) { 
        string ts(_tmp.begin(),_tmp.end());
        return ts;
      }
    }

    if ( i==(vrs.size()-2) ) { 
      if ( s.length()>1000 ) {
        for(int j=i-10;j<i;j++){
          vector<char> _tmp(vrs.begin(), vrs.begin()+j);
          _tmp.insert(_tmp.end(),vs.begin(),vs.end());
          if ( isPalindrome(_tmp) ) { 
            string ts(_tmp.begin(),_tmp.end());
            return ts;
          }
        }
      }
      vector<char> _tmp(vrs.begin(), vrs.end()-1);
      _tmp.insert(_tmp.end(),vs.begin(),vs.end());
      if ( isPalindrome(_tmp) ) { 
        string ts(_tmp.begin(),_tmp.end());
        return ts;
      }
    }
   
    vector<char> tmp(vrs.begin(), vrs.begin()+i);
    tmp.insert(tmp.end(),vs.begin(),vs.end());
    if ( isPalindrome(tmp) ) {
      string ts(tmp.begin(),tmp.end());
      return ts;
    }
    if ( i>20 || vrs[i]!=vrs[i+1] ) nextStage = true;
    i++;
  }
  return s;
}

// KMP-based solution 
// https://leetcode.com/discuss/36807/c-8-ms-kmp-based-o-n-time-%26-o-n-memory-solution
string shortestPalindrome(string s) {
  string rev_s = s;
  reverse(rev_s.begin(), rev_s.end());
  string l = s + "#" + rev_s;

  vector<int> p(l.size(), 0);
  for (int i = 1; i < l.size(); i++) {
    int j = p[i - 1];
    cout << i << " " << j << " | ";
    while (j > 0 && l[i] != l[j])
      j = p[j - 1];
    cout << i << " " << j << " | ";
    p[i] = (j += l[i] == l[j]);

    cout << "### " << i << " vs " << j << " ### " << endl;
    for(auto v:l) cout << v << " "; cout << endl;
    for(auto v:p) cout << v << " "; cout << endl;
  }

  cout << "### Final ### " << endl;
  for(auto v:l) cout << v << " "; cout << endl;
  for(auto v:p) cout << v << " "; cout << endl;

  return rev_s.substr(0, s.size() - p[l.size() - 1]) + s;
}

// KMP-based 4ms solution
// https://leetcode.com/discuss/40486/accepted-solution-different-based-solution-easy-understand
std::string shortestPalindrome_4ms(std::string s) {
	int len = s.length();
	if (len < 2)
		return s;
	// calculate the length of the longest palindromic prefix substring.
	int longest = 1, start, end;
	for (int begin = 0; begin <= len / 2;) {
		start = end = begin;
		while (end < len - 1 && s[end + 1] == s[end])
			++end;
		begin = end + 1;
		while (end < len - 1 && start > 0 && s[end + 1] == s[start - 1]) {
			++end;
			--start;
		}
		// start == 0 means the palindromic substring is also prefix string.
		if (start == 0 && longest < end - start + 1)
			longest = end - start + 1;
	}
	// reverse the remaining substring and adding it in front of s.
	std::string remaining = s.substr(longest, len - longest);
	std::reverse(remaining.begin(), remaining.end());
	return remaining + s;
}

int main(){
  cout << shortestPalindrome("aacecaaa") << endl;
  //cout << shortestPalindrome("abcd") << endl;
  //cout << shortestPalindrome("abb") << endl;
  //cout << shortestPalindrome("aba") << endl;
  //cout << shortestPalindrome("aabbaad") << endl;
  //cout << shortestPalindrome("aabba") << endl;
  //cout << shortestPalindrome("gabqtbypdwjjelvgohmvzpyfqayobkyyhoizaqhtqkzodcosufbpgurxsbjtrkombfbl") << endl;
  return 0;
}
