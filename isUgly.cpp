
#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

bool isUgly(int num) {
  if ( num==0 )  return false; 
  if ( num==1 )  return true;
  if ( num%7 == 0 ) return false;
  if ( num%11 == 0 ) return false;
  if ( num%13 == 0 ) return false;
  while(num%2==0) num/=2;
  while(num%3==0) num/=3;
  while(num%5==0) num/=5;
  return (num==1) ? true : false;
}

int main(){

  cout << isUgly(6) << endl;
  cout << isUgly(8) << endl;
  cout << isUgly(14) << endl;
  return 0;
}
