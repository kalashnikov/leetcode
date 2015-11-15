#include <iostream>
#include <vector>

using namespace std;

void moveZeroes(vector<int>& nums) {
  if (nums.size()<2) return;
  int i = 0, j = 0;
  while(nums[i]!=0) i++;
  j = i;
  while(nums[j]==0) j++;
  while(i<nums.size()&&j<nums.size()) {
    while(nums[i]==0&&nums[j]!=0) swap(nums[i++], nums[j]);
    while(nums[i]!=0) i++;
    while(nums[j]==0) j++;
  }
  return;
}

int main(){
  vector<int> s0 { 2, 1};
  moveZeroes(s0);
  for(auto v:s0) cout << v << " "; cout << endl;
  vector<int> s1 { 0, 1, 0, 3, 12 };
  moveZeroes(s1);
  for(auto v:s1) cout << v << " "; cout << endl;
  vector<int> s2 { 1, 0};
  moveZeroes(s2);
  for(auto v:s2) cout << v << " "; cout << endl;
  vector<int> s3 {4,2,4,0,0,3,0,5,1,0};
  moveZeroes(s3);
  for(auto v:s3) cout << v << " "; cout << endl;
  return 0;
}
