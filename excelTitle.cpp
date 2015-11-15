#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

// 1 -> A
// 2 -> B
// 3 -> C
// ...
// 26 -> Z
// 27 -> AA
// 28 -> AB 
string convertToTitle2(int n) {
  int cnt = 0;
  long long i = 1, j = 0, l = 0;
  while(l<n) { 
    i*=26; 
    l+=i; 
    cnt++;
    cout << i << endl;
  }
  char s[cnt+1];
  while(j<cnt){
    i /= 26;
    l = (n/i);
    if (l>26) l = 26; 
    else if (n-(l*i)==0 && (cnt-j)==2) l--;
    char c = char(l + 'A'-1);
    printf("n:%d | i:%lld l:%lld c:%c \n", n, i, l, c);
    s[j++] = c;
    n= n-l*i;
  }
  s[j] = '\0';
  return s;
}

// https://leetcode.com/discuss/42441/short-0ms-c-solution
string convertToTitle(int n) {
  string result;
  while (n) {
    //cout << char('A' + (n - 1) % 26) << endl;
    result.push_back('A' + (n - 1) % 26), n = (n - 1) / 26;    
  }
  reverse(result.begin(), result.end());
  return result;
}

int titleToNumber(string s) {
  int ans = 0; 
  for(int i=0;i<s.length();i++){
    ans = ans*26 + s[i]-'A'+1;
  }
  return ans;
}

int main(){
  cout << convertToTitle(26) << endl;
  cout << convertToTitle(27) << endl;
  cout << convertToTitle(28) << endl;
  cout << convertToTitle(701) << endl;
  cout << convertToTitle(702) << endl;
  cout << convertToTitle(703) << endl;
  cout << convertToTitle(18278) << endl;
  cout << convertToTitle(18279) << endl;
  //cout << convertToTitle(1000000001) << endl;
  cout << convertToTitle(52) << endl;

  cout << titleToNumber("Z") << endl;
  cout << titleToNumber("AA") << endl;
  cout << titleToNumber("AZ") << endl;
  cout << titleToNumber("AAA") << endl;

  return 0;
}
