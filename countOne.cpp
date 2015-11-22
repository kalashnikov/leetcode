#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

// @ StefanPochmann
// https://leetcode.com/discuss/44281/4-lines-o-log-n-c-java-python?show=44357#c44357 
int countDigitOne(int n) {
  int ones = 0;
  for (long long m = 1; m <= n; m *= 10) {
    int a = n/m, b = n%m;
    ones += (a + 8) / 10 * m + (a % 10 == 1) * (b + 1);
  }
  return ones;
}

// brute-force, TLE
int countDigitOne(int n) {
  if ( n < 1 ) return 0;
  if ( n <10 ) return 1;

  static vector<pair<int,int>> cache{{10,2}};

  int sum = 0, i = 1;
  if ( n > cache.back().first ) {
    i   = cache.back().first+1;
    sum = cache.back().second;
  }

  bool f = true;
  int j, z, ls;
  while(i<=n){
    j = i, f = true;
    while(j) {
      z = j;
      if ( j%10==1 ) { 
        f = false; 
        sum++;
      }
      //sum += (j%10)==1;
      j/=10;
    }
    //cout << i << " " << sum << " | " << (z!=1&&z!=9&&(ls!=sum)) << endl;
    //if ( z!=1&&z!=9&&(ls!=sum) ) { i+=10; ls = 0; }
    cout << i << " " << sum << " | " << (!f&&z!=9&&(ls!=sum)) << endl;
    if ( !f&&z!=9&&(ls!=sum) ) { i+=10; ls = 0; }
    else { 
      i++; ls = sum; 
    } 
      i++; ls = sum; 
  }

  cache.push_back({n,sum});
  return sum; 
}

int main(){
  cout << countDigitOne(13) << endl;
  cout << countDigitOne(100) << endl;  // 21
  cout << countDigitOne(200) << endl;  // 140
  cout << countDigitOne(300) << endl;  // 160
  cout << countDigitOne(1001) << endl; // 303
  //cout << countDigitOne(100100) << endl;
  //cout << countDigitOne(824883294) << endl;
  return 0;
}
