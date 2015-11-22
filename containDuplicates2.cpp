#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

// 48ms using set. 
// https://leetcode.com/discuss/50568/c-6-line-solution-simple-code-and-easy-understanding
bool containsNearbyDuplicate2(vector<int>& nums, int k) {
  set<int> cand;
  for (int i = 0; i < nums.size(); i++) {
    if (i > k) cand.erase(nums[i-k-1]);
    if (!cand.insert(nums[i]).second) return true;
  }
  return false;
}

// 28ms
bool containsNearbyDuplicate(vector<int>& nums, int k) {
  if(nums.size()<2) return false;
  unordered_map<int, int> db; 
  db.reserve(nums.size()); 
  for(int i=0;i<nums.size();i++){
    if(db.count(nums[i])){
      if ( i-db[nums[i]]<=k ) 
        return true;
      db[nums[i]]=i;
    } else {
      db[nums[i]]=i;
    }
  }
  return false;
}

int main(){
  vector<int> i1 { 1,2,3,4,5,1,3,4 }; 
  cout << containsNearbyDuplicate(i1, 4) << endl; 
  vector<int> i2 { 1,2,1 }; 
  cout << containsNearbyDuplicate(i2, 0) << endl; 
  return 0;
}
