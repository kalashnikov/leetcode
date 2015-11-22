#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

int maxSubArray(vector<int>& nums) {
  if(nums.size()==0) return 0;
  int ans = nums[0], pre = nums[0];
  for(int i=1;i<nums.size();i++){
    pre = max(pre+nums[i], nums[i]);
    ans = max(ans, pre);
  }
  return ans;
}

int main(){
  vector<int> i1 { -2,1,-3,4,-1,2,1,-5,4 };
  cout << maxSubArray(i1) << " 6" << endl;
  return 0;
}
