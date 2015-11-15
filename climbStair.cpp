#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

int climbStairs(int n) {
  static unordered_map<int, int> cache; 
  if ( cache.size() == 0 ) cache[0] = cache[1] = 1;
  if ( cache.count(n) ) return cache[n]; 
  vector<int> v(n+1,0);
  v[0] = v[1] = 1;
  for(int i=2;i<=n;i++){
    v[i] = v[i-1] + v[i-2];
  }
  cache[n] = v[n];
  return v[n];
}

int main(){
  cout << climbStairs(3) << endl;
  cout << climbStairs(6) << endl;
  return 0;
}
