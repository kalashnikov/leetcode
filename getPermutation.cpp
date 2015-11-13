#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <sstream>

using namespace std;

// 123, 132, 213, 231, 312, 321
string getPermutation(int n, int k) {
  k--;
  vector<int> ref; 
  for(int i=0;i<n;i++) ref.push_back(i+1);

  stringstream ss;
  for(int v=1, i=n;i>0;i--){
    v=1;
    for(int j=1;j<i;j++) {
      v*=j;
    }
    //cout << " " << k/v << "*" << v << endl;
    ss << ref[k/v];
    ref.erase(ref.begin()+k/v);
    k -= k/v * v; 
  }
  return ss.str();
}

int main(){

  cout << getPermutation(3, 1) << endl;
  cout << getPermutation(3, 2) << endl;
  cout << getPermutation(3, 3) << endl;
  cout << getPermutation(3, 4) << endl;
  cout << getPermutation(3, 5) << endl;
  cout << getPermutation(3, 6) << endl;

  return 0;
}
