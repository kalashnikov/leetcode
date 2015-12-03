#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

bool canJump(vector<int>& nums) {
  if(nums.size()==0) return true;
  int n = nums.size(), maxv = nums[0];
  for(int i=1;i<n-1;i++){
    if(maxv>=n || i > maxv) break;
    maxv = max(maxv, i+nums[i]); 
  }
  return (maxv>=n-1) ? true : false;
}

int main(){
  vector<int> i0 { 0}; 
  cout << canJump(i0) << " 1" << endl;
  vector<int> i1 { 2,3,1,1,4}; 
  cout << canJump(i1) << " 1" << endl;
  vector<int> i2 { 3,2,1,0,4}; 
  cout << canJump(i2) << " 0" << endl;
  return 0;
}
