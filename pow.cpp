#include <iostream>
#include <vector>
#include <list>

using namespace std;

// 8ms, recursive 
double pow(double x, int n) {
  if(n == 0)
    return 1;
  if(n<0){
    n = -n;
    x = 1/x;
  }
  return (n%2 == 0) ? pow(x*x, n/2) : x*pow(x*x, n/2);
}

// 4ms, no need to handle negative x, but need handle negative n 
double myPow(double x, int n) {
  if(n==0||x==1) return 1;
  if(x==-1) return (n%2!=0) ? -1 : 1;
  if(n==1) return x;

  bool rev = n < 0 ? true: false;
  if ( rev ) n = -n;
  //bool neg = x < 0 ? true: false;
  //if ( neg ) x = -x;
  //if ( neg && n%2==0 ) neg = false;
  
  double ans = 1, aux = x;
  while(n) {
    if(n&1)  ans *= aux;
    n>>=1; 
    aux *= aux;
  }
  if ( rev ) ans = 1/ans; 
  //if ( neg ) ans = -ans; 
  return ans;
}

int main(){
  cout << myPow(-1,3) << " -1" << endl;
  cout << myPow(2,-2) << " 0.25" << endl;
  cout << myPow(2,10) << " 1024" << endl;
  cout << myPow(3,11) << " 177147" << endl;
  cout << myPow(-13.62608,3) << " -2529.95504" << endl;
  return 0;
}
