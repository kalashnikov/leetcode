#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

//=========================================================//
// https://leetcode.com/discuss/18242/clean-iterative-solution-binary-searches-with-explanation
int left(vector<int>& nums, int target) {
  int n = nums.size(), l = 0, r = n; 
  while (l < r) {
    int mid = (l + r) / 2;
    if (nums[mid] < target) l = mid + 1;
    else r = mid;
  }
  return l;
}
vector<int> searchRange(vector<int>& nums, int target) {
  int n = nums.size();
  int l = left(nums, target);
  if (l < 0 || l >= n || nums[l] != target) return {-1, -1};
  return {l, left(nums, target + 1) - 1};
}
//=========================================================//

vector<int> searchRange(vector<int>& nums, int target) {
  if( nums.size()==0  || (nums.size()<2 && nums[0]!=target) || 
     nums[0] > target || nums.back() < target ) 
    return vector<int>{-1,-1};
  if(nums[0]==target && nums.back()==target) 
    return vector<int>{0, (int)nums.size()-1}; 

  vector<int> ans { -1, -1 }; 

  int i=0, j=nums.size(), idx = 0; 
  while(i<j){
    idx = i+(j-i)/2;
    cout << i << " " << j << " | " << idx << endl;
    if(nums[idx]==target) break;
    if(nums[idx] > target) j = idx;
    else i = idx+1;
  }

  if(nums[idx]==target) { 
    ans[0] = ans[1] = idx;
    while(ans[0] && nums[ans[0]-1]==target) --ans[0]; 
    while(ans[1] < nums.size() - 1 && nums[ans[1]+1]==target) ++ans[1]; 
  }

  return ans;
}

int main(){

  vector<int> i1 {8,8,8,8,8,8,9,9,9,9,10}; 
  auto p1 = searchRange(i1, 10);
  if(p1.size()==2) cout << p1[0] << " " << p1[1] << endl; 

  vector<int> i2 {4,5}; 
  auto p2 = searchRange(i2, 4);
  if(p2.size()==2) cout << p2[0] << " " << p2[1] << endl; 
  return 0;
}
