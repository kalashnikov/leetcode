#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <unordered_map>

using namespace std;
  
unordered_map<int, int> cache;

int numSquares(int n) {
  set<int> s;
  vector<int> vec;
  for( int i=1; i*i<=n; i++){
    if ( i*i == n ) {
      cache[n]=1;
      return 1;
    }
    s.insert(i*i);
    vec.push_back(i*i);
    cache[i*i] = 1;
  }
  
  for( int i = vec.size()-1; i > vec.size()/2-1; i--){
    if ( s.find(n-vec[i])!=s.end() ){
      cache[n] = 2;
      return 2;
    }
  }
 
  int v1, v2;
  int least = n-vec.back()+1;
  for( int i = vec.size()-1; i > vec.size()/2-1; i--){
    v1 = vec[i];
    if ( n%v1==0 && n/v1 < least ) {
      least = n/v1; 
    }
    if (least > 3) { 
      for( int j=0; j<i; j++){
        if ( s.find(n-v1-vec[j])!=s.end()) { 
          //cout << n << " = 3: " << v1 << " " << vec[j] << endl;
          least = 3;
          cache[n]=3;
          return 3;
        }
      }
    }
  
    if ( cache.find(n-v1)!=cache.end() ) 
      v2 = cache[n-v1];
    else { 
      v2 = numSquares(n-v1);
      cache[n-v1]=v2;
    }
    if ( least > v2 + 1 ) { 
      least = v2 + 1;
    }

  }

  return least;
}

int numSquares_dp(int n) {
  if ( n <=0 ) return 0;

  int *dp = new int[n+1];
  dp[0] = 0;

  for (int i=1; i<=n; i++ ) {
    int m = n;
    for (int j=1; i-j*j >= 0; j++) {
      m = min (m, dp[i-j*j] + 1);
    }
    dp[i] = m;
  }

  return dp[n];
}

int main(){

  //cout << "Ans[4]: " << numSquares(4) << endl;
  //cout << "Ans[6]: " << numSquares(6) << endl;
  //cout << "Ans[12]: " << numSquares(12) << endl;
  //cout << "Ans[13]: " << numSquares(13) << endl;
  //cout << "Ans[14]: " << numSquares(14) << endl;
  //cout << "Ans[15]: " << numSquares(15) << endl;
  //cout << "Ans[87]: " << numSquares(87) << endl;
  //cout << "Ans[459]: " << numSquares(459) << endl;
  //cout << "Ans[480]: " << numSquares(480) << endl;
  //cout << "Ans[7168]: " << numSquares(7168) << endl;


  for( int i=0;i<10000;i++) {
    numSquares_dp(i);
  }

  return 0;
}
