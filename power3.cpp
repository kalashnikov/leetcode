#include <iostream>
#include <vector>
#include <unordered_set>
#include <list>

using namespace std;

// https://leetcode.com/discuss/78500/math-solution
// http://stackoverflow.com/a/24274850/1672429
bool isPowerOfThree(int n) {
  return n > 0 && (1162261467 % n == 0);
}

bool isPowerOfThree(int n) {
  if( n > INT_MAX || n < 1 ) return false;
  if( n&1==0 ) return false;
  
  if(n==1) return true;
  if(n==3) return true;
  if(n==9) return true;
  if(n==27) return true;
  if(n==81) return true;
  if(n==243) return true;
  if(n==729) return true;
  if(n==2187) return true;
  if(n==6561) return true;
  if(n==19683) return true;
  if(n==59049) return true;
  if(n==177147) return true;
  if(n==531441) return true;
  if(n==1594323) return true;
  if(n==4782969) return true;
  if(n==14348907) return true;
  if(n==43046721) return true;
  if(n==129140163) return true;
  if(n==387420489) return true;
  if(n==1162261467) return true;

  return false;
}

int main(){

  char c = ' ';
  long val = 1;
  while(val<INT_MAX){
    cout << "(" << bitset<32>(val) << ") " << val << endl;
    val *= 3;
    c = ',';
  }
  cout << endl;

  return 0;
}
