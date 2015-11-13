#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

int divide(int dividend, int divisor) {
  if (!divisor || (dividend == INT_MIN && divisor == -1))
    return INT_MAX;
  if ( divisor==0 ) return 0;
  if ( divisor==1 ) return dividend;

  long long di = dividend;
  long long ds = divisor;
  
  bool minus1 = ds < 0 ? true : false;
  if ( minus1 ) ds = -ds;

  bool minus2 = di < 0 ? true : false;
  if ( minus2 ) di = -di;

  long long ans = 0;
  if ( di < ds ) { 
    return 0;
  } else if ( di==ds ) { 
    ans = 1; 
  } else if ( ds== 1 ) { 
    ans = di; 
  } else { 
    while ( ds < di ) {
      long long tmpa = 1, tmp = ds, last;
      while(tmp <= di && tmp > 0 ) {
        last = tmp;
        tmp  <<= 1;
        tmpa <<= 1;
      }
      di -= last; 
      ans += (tmpa >> 1 );
    }
  }
  if ( minus1 ) ans = -ans;
  if ( minus2 ) ans = -ans;
  return ans;
}

int main() {

  cout << divide(1,-1) << endl;
  cout << divide(9,5) << endl;
  cout << divide(3,4) << endl;
  cout << divide(100,26) << endl;
  cout << divide(2147483647,2) << " " << 2147483647/2 << endl;
  cout << divide(-1010369383,-2147483648) << endl;
  cout << divide(-2147483648,2) << endl;
  cout << divide(-2147483648,-1) << " vs " << 2147483647 << endl;

  return 0;
}
