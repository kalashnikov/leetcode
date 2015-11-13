#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

// https://leetcode.com/discuss/18523/shortest-code-possible-in-c 
int reverse(int x) {
  long long res = 0;
  while(x) {
    res = res*10 + x%10;
    x /= 10;
  }
  return (res<INT_MIN || res>INT_MAX) ? 0 : res;
}

int reverse2(int x) {
  if ( x==0 ) return x; 
  long y = x, ans = 0; 
  if ( y > INT_MAX ) return INT_MIN;
  if ( y < INT_MIN ) return INT_MAX;
  bool neg = (y<0); y = abs(y);
 
  while(y!=0){
    ans = ans*10 + y%10; 
    y /= 10;
  }
  if ( ans >= INT_MAX ) return 0;
  return (neg)?-ans:ans;
}

int main(){
  cout << reverse(123) << endl;
  cout << reverse(-123) << endl;
  cout << reverse(2147483647) << endl;
  return 0;
}
