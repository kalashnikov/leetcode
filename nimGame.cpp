#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

bool canWinNim(int n) {
  if ( n < 4 ) return true;
  return (n%4==0) ? false : true;
}

int main(){
  cout << "4: " << canWinNim(4) << endl;
  return 0;
}
