#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

// Sliding Window solution 
// https://leetcode.com/discuss/35678/c-6ms-solution-sliding-window
int minSubArrayLen(int s, vector<int>& nums) {
  int num_len= nums.size();
  int left=0, right=0, total=0, min_len= num_len+1;
  while (right < num_len) {
    // move right silder forward till total >= s
    do { total += nums[right++]; } while (right<num_len && total< s);
    // move left slider forward while maintaining total >= s
    while (left<right && total-nums[left]>=s) total -= nums[left++];
    // record if it's the minimum
    if (total>=s && min_len> right- left) 
      min_len= right- left;
  }
  return min_len<=num_len ? min_len: 0;
}

// Another similar solution
// https://leetcode.com/discuss/35464/c-simple-o-n-solution
int minSubArrayLen(int s, vector<int>& nums) {
  int firstPos = 0, sum = 0, minLength = INT_MAX;
  for(int i = 0; i<nums.size(); i++) {
    sum += nums[i];
    while(sum >= s) {
      minLength = min(minLength, i - firstPos + 1);
      sum -= nums[firstPos++];
    }
  }

  return minLength == INT_MAX? 0 : minLength;
}

int minSubArrayLen(int s, vector<int>& nums) {
  if(nums.size()==0) return 0;
  int n = nums.size();
  int ans = n, lim = 0, val;
  if(nums[0]>=s) return 1;
  for(int i=1;i<n;i++){
    if(nums[i]>=s) return 1;
    nums[i] += nums[i-1];
    if(nums[i]>=s){
      lim = max(-1,i-ans);
      for(int j=i-1;j>=lim;j--){
        val = (j==-1) ? 0 : nums[j];
        if(nums[i] - val >=s) {
          ans = min(ans, i-j);
          if(ans==2) return 2;
          break;
        }
      }
    }
  }
  if ( nums.back() < s ) return 0;
  return ans;
}

int main(){
  vector<int> i1 {2,3,1,2,4,3};
  cout << minSubArrayLen(7,i1) << " 2" << endl; 
  vector<int> i2 {1,2,3,4,5};
  cout << minSubArrayLen(11,i2) << " 3" << endl; 
  vector<int> i3 {10,2,3};
  cout << minSubArrayLen(6,i3) << " 1" << endl; 
  vector<int> i4 {2,3,1,1,1,1,1};
  cout << minSubArrayLen(5,i4) << " 2" << endl; 
  return 0;
}
