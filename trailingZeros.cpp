#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

int trailingZeroes(int n) { 
  if ( n<5 ) return 0;
  long long ans = 0, f = 5;
  while(f<=n){
    ans += n/f; 
    f *= 5;
  }
  return ans;
}

int main(){
  cout << trailingZeroes(15) << endl;
  cout << trailingZeroes(25) << endl;
  cout << trailingZeroes(125) << endl;
  cout << trailingZeroes(2147483647) << endl;
  return 0;
}
