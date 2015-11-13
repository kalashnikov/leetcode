#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

bool isPowerOfTwo(int n) {
  if(n==0) return false;
  if(n==1) return true;
  if(n<0 ) return false;
  return ((n&(n-1))==0) ? true : false;
}

int main(){

  cout << isPowerOfTwo(2) << endl;
  cout << isPowerOfTwo(3) << endl;
  cout << isPowerOfTwo(4) << endl;
  cout << isPowerOfTwo(5) << endl;
  cout << isPowerOfTwo(8) << endl;
  cout << isPowerOfTwo(-2147483648) << endl;
  return 0;
}
