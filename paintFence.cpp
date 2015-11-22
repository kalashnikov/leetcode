#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

int numWays(int n, int k) {
  if ( n==0 || k==0 ) return 0; 
  if ( n>2 && k<2  ) return 0;
  vector<int> v(n,0);
  v[0] = k; v[1] = k*k;
  for(int i=2;i<n;i++)
    v[i] = (k-1)*(v[i-1]+v[i-2]); 
  return v[n-1];
}

int main(){
  cout << numWays(1,1) << endl;
  cout << numWays(3,2) << endl;
  return 0;
}
