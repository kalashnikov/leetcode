#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

// https://leetcode.com/discuss/17000/share-my-one-pass-constant-space-10-line-solution
void sortColors(vector<int>& nums) {
  int second=nums.size()-1, zero=0;
  for (int i=0; i<=second; i++) {
    while (numsA[i]==2 && i<second) swap(nums[i], nums[second--]);
    while (numsA[i]==0 && i>zero)   swap(nums[i], nums[zero++]);
  }
}

void sortColors(vector<int>& nums) {
  if(nums.size()<2) return;
  int cur = 0, idx1=1, idx2 = nums.size()-1;
  while(cur <= idx2 && idx1<=idx2) { 
    while (cur<=idx2  && nums[cur]==0)  cur++;
    idx1 = cur + 1;
    while (idx1<=idx2 && nums[idx1]==1) idx1++;
    while (cur<=idx2  && nums[idx2]==2) idx2--;
    while (idx1<=idx2 && nums[cur]==1)  swap(nums[cur],nums[idx1++]); 
    while (cur<=idx2  && nums[cur]==2)  swap(nums[cur],nums[idx2--]); 
    
    //cout << cur << " " << idx1 << " " << idx2 << " | ";
    //for(auto v:nums) cout << v << " "; cout << endl;
  }
  return ;
}

int main(){
  vector<int> i1 { 2,1,0,2,2,0,1,0,1,2 };
  sortColors(i1); 
  for(auto v:i1) cout << v << " "; cout << endl;
  vector<int> i2 { 2,2,1 };
  sortColors(i2); 
  for(auto v:i2) cout << v << " "; cout << endl;
  vector<int> i3 { 0,0,1,0,1,1 };
  sortColors(i3); 
  for(auto v:i3) cout << v << " "; cout << endl;
  vector<int> i4 { 2,1 };
  sortColors(i4); 
  for(auto v:i4) cout << v << " "; cout << endl;
  return 0;
}
