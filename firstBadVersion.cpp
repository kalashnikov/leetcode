#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

vector<bool> v;
bool isBadVersion(int version){
  return !v[version];
}

int firstBadVersion(int n) {
  int lower = 1, upper = n, mid;
  while(lower < upper) {
    mid = lower + (upper - lower) / 2;
    if(!isBadVersion(mid)) lower = mid + 1;   /* Only one call to API */
    else upper = mid;
  }
  return lower;   /* Because there will alway be a bad version, return lower here */
}

int main(){
  v.clear();
  vector<bool> v2{ 0,0,1,1};
  for(auto a:v2) v.push_back(a);
  cout << firstBadVersion(v.size()) << endl;
  
  v.clear();
  vector<bool> v3{ 0,0,0,1};
  for(auto a:v3) v.push_back(a);
  cout << firstBadVersion(v.size()) << endl;
  return 0;
}
