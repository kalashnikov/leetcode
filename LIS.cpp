#include <iostream>
#include <vector>
#include <list>

using namespace std;

// https://leetcode.com/discuss/67533/c-typical-dp-2-solution-and-nlogn-solution-from-geekforgeek
// There's a typical DP solution with O(N^2) Time and O(N) space 
// DP[i] means the result ends at i
// So for dp[i], dp[i] is max(dp[j]+1), for all j < i and nums[j] < nums[i]
int lengthOfLIS_dp(vector<int>& nums) {
  const int size = nums.size();
  if (size == 0) { return 0; } 
  vector<int> dp(size, 1);
  int res = 1;
  for (int i = 1; i < size; ++i) {
    for (int j = 0; j < i; ++j) {
      if (nums[j] < nums[i]) {
        dp[i] = max(dp[i], dp[j]+1);
      }
    }
    res = max (res, dp[i]);
  }
  return res;
}

int lower_bound(const vector<int>& res, const int& target) {
  int lo = 0, hi = res.size();
  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (res[mid]>=target) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  return lo;
}

// https://leetcode.com/discuss/67554/9-lines-c-code-with-o-nlogn-complexity
int lengthOfLIS(vector<int>& nums) {
  vector<int> res;
  for(int i=0; i<nums.size(); i++) {
    //auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
    //if(it==res.end()) res.push_back(nums[i]);
    //else *it = nums[i];
    int it = lower_bound(res, nums[i]);
    if ( it==res.size() ) res.push_back(nums[i]);
    else res[it] = nums[i];
  }
  return res.size();
}

int main(){
  vector<int> i1 {10, 9, 2, 5, 3, 7, 101, 18};
  cout << lengthOfLIS(i1) << " 4" << endl;
  vector<int> i3 {2, 2};
  cout << lengthOfLIS(i3) << " 1" << endl;
  vector<int> i2 {1,3,6,7,9,4,10,5,6};
  cout << lengthOfLIS(i2) << " 6" << endl;
  return 0;
}
