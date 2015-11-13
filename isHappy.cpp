#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <cmath>

using namespace std;

bool isHappy(int n) {
  if ( n==0 ) return false;
  if ( n==1 ) return true;
 
  set<int> s; 

  int cnt = 0, d = 0;
  while(1){
    while(n!=0){
      d = n%10;
      cnt += d * d; 
      n/=10;
    }
    if ( cnt == 1 ) { 
      return true;
    } else if ( s.find(cnt)!=s.end() ) {
      return false; 
    } else {
      s.insert(cnt);
      n = cnt;
      cnt = 0; 
    }
  }
  return false;
}

int main(){
  cout << isHappy(19) << endl;
  return 0;
}
