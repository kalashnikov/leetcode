#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <list>

using namespace std;

int mySqrt(int x) {
  if ( x<2 ) return x;
  
  unsigned long t; 
  if ( x < 10 ) {
    t = 2;
  } else { 
    for ( unsigned long  i = 2; i<x; i<<=1) {
      if ( (i*i) > x ) {
        t = i>>1;
        break;
      }
    }
    for ( ; t < x ; t*=2 ){
      if ( ( t*t ) > x ) {
        t = t/2;
        break;
      }
    }
  } 
  for ( ; t < 2*t; t++) {
    if ( t*t > x) 
      return (t-1);
  }
}

int main(){

  for ( int i =0;i<256; i++) {
    if ( mySqrt(i) != (int)sqrt(i) ) {
      cout << i << ": " << mySqrt(i) << " vs " << (int)sqrt(i) << endl;
    }
  }
  cout << mySqrt(2147483647) << endl;

  return 0;
}
