#include <iostream>
#include <cmath>

using namespace std;

// https://leetcode.com/discuss/33500/an-easy-lines-code-only-reversing-till-half-and-then-compare
bool isPalindrome(int x) {
  if(x<0|| (x!=0 &&x%10==0)) return false;
  int sum=0;
  while(x>sum)
  {
    sum = sum*10+x%10;
    x = x/10;
  }
  return (x==sum)||(x==sum/10);
}

bool isPalindrome(int x) {
  if ( x < 0  ) return false; 
  if ( x < 10 ) return true;
  int n = 0, y = x; 
  while(y!=0) { y/=10; n++; }
  bool dif = n%2==0 ? false : true;
  n /= 2, y = 0;
  while(n>0){
    y  = 10*y + x%10;
    x /= 10; 
    n--;
  }
  if ( dif ) x/=10;
  if ( x==y ) return true;
  return false;
}

int main(){
  cout << isPalindrome(0) << endl;
  cout << isPalindrome(1) << endl;
  cout << isPalindrome(1331) << endl;
  cout << isPalindrome(14641) << endl;
  cout << isPalindrome(137731) << endl;
  return 0;
}
