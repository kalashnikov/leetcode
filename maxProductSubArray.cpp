#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

// https://leetcode.com/discuss/11923/sharing-my-solution-o-1-space-o-n-running-time 
int maxProduct2(vector<int>& nums) {
  if(nums.size()==0) return 0;

  int maxherepre = nums[0];
  int minherepre = nums[0];
  int maxsofar   = nums[0];
  int maxhere, minhere;

  for (int i = 1; i < nums.size(); i++) {
    maxhere = max(max(maxherepre * nums[i], minherepre * nums[i]), nums[i]);
    minhere = min(min(maxherepre * nums[i], minherepre * nums[i]), nums[i]);
    maxsofar = max(maxhere, maxsofar);
    maxherepre = maxhere;
    minherepre = minhere;
  }
  return maxsofar;
}

// DP. 8ms
int maxProduct(vector<int>& nums) {
  if(nums.size()==0) return 0;
  int tmin, tmax;
  int ans = nums[0], maxpro = nums[0], minpro = nums[0];
  for(int i=1;i<nums.size();i++){
    tmin   = min(min(nums[i]*minpro, nums[i]*maxpro),nums[i]);
    tmax   = max(max(nums[i]*minpro, nums[i]*maxpro),nums[i]);
    minpro = tmin;
    maxpro = tmax;
    ans    = max(ans, maxpro);
  }
  return ans; 
}

int main(){
  vector<int> i1 { 2,3,-2,4 };
  cout << maxProduct(i1) << " 6" << endl;
  vector<int> i2 { -2,3,-4 };
  cout << maxProduct(i2) << " 24" << endl;
  vector<int> i3 { -3,0,1,-2 };
  cout << maxProduct(i3) << " 1" << endl;
  vector<int> i4 { -2,0,-1 };
  cout << maxProduct(i4) << " 0" << endl;
  vector<int> i5 { 2,-5,-2,-4,3 };
  cout << maxProduct(i5) << " 24" << endl;
  vector<int> i6 {1,2,-1,-2,2,1,-2,1,4,-5,4};
  cout << maxProduct(i6) << " 1280" << endl;
  return 0;
}
