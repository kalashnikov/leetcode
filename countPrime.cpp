#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <cmath>

using namespace std;

int countPrimes(int n) {
  if ( n < 2 ) return 0;

  bool ans[n];
  memset(ans, true, sizeof(ans));

  ans[0]=0; ans[1]=0;
  int limit = sqrt(double(n))+1;
  for(int i=2;i<limit;i++){
    if(ans[i]==0) continue;
    for(int j=i*i;j<n;j+=i){
      ans[j]=0;
    }
  }

  int cnt = 0;
  for(int i=2;i<n;i++){
    if(ans[i]==1)
      cnt++;
  }

  return cnt;
}

int main(){

  cout << countPrimes(1000) << endl;
  cout << countPrimes(49979) << endl;

  return 0;
}
