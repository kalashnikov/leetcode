#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

bool containsDuplicate(vector<int>& nums) {
  if ( nums.size()<2 ) return false;
  unordered_set<int> db;
  db.reserve(nums.size());
  for(auto v:nums){
    if(db.count(v)) return true;
    db.insert(v);
  }
  return false;
}

int main(){
  vector<int> s1 { 1,2,3,4}; 
  cout << containsDuplicate(s1) << endl;
  return 0;
}
