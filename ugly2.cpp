#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <algorithm>

using namespace std;

// 1, 2, 3, 4, 5, 6, 8, 9, 10, 12
int nthUglyNumber(int n) {
  if ( n==1 ) return 1;

  static vector<int> cache {1}; 
  list<int> l1 {1}, l2 {1}, l3 {1};

  if ( cache.size() > n ) { 
    return cache[n-1];
  }

  int nth = 1, val;
  while(nth!=n) {
    val = min(min(l1.front()*2, l2.front()*3), l3.front()*5);
    if ( l1.front()*2 == val ) l1.pop_front();
    if ( l2.front()*3 == val ) l2.pop_front();
    if ( l3.front()*5 == val ) l3.pop_front();
    l1.push_back(val);l2.push_back(val);l3.push_back(val);
    nth++;
  }
  return val;
}

int main(){
  cout << nthUglyNumber(7) << endl;
  cout << nthUglyNumber(10) << endl;
  cout << nthUglyNumber(11) << endl;
  return 0;
}
