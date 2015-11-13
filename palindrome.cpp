#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

bool isPalindrome(string s) {
  if ( s[0]=='\0' || s.length()==0 ) return true;
  int i = 0, j = s.length()-1;
  char c1, c2;
  while(  i<j ){
    //while ( i < j && ( s[i] < 'A' || s[i] > 'z' ) ) i++;
    //while ( i < j && ( s[j] < 'A' || s[j] > 'z' ) ) j--;
    while ( i < j && !isalnum(s[i])) i++;
    while ( i < j && !isalnum(s[j])) j--;
    //cout << s[i] << " vs " << s[j] << endl;
    c1 = s[i], c2 = s[j]; 
    if ( c1 < 'a' ) c1 += 32; 
    if ( c2 < 'a' ) c2 += 32; 
    if (c1!=c2) 
      return false;
    i++; j--;
  }
  return true;
}

int main(){

  string s1 = "A man, a plan, a canal: Panama";
  string s2 = "race a car";
  string s3 = "1a2";

  cout << isPalindrome(s1) << endl;
  cout << isPalindrome(s2) << endl;
  cout << isPalindrome(s3) << endl;

  return 0;
}
