#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/discuss/61514/understood-solution-space-without-modifying-explanation 
// Similiar to problem: Finding cycle in linked list
// Also ref: http://keithschwarz.com/interesting/code/?dir=find-duplicate
// 12ms 
int findDuplicate(vector<int>& nums)
{
  if (nums.size() > 1)
  {
    int slow = nums[0];
    int fast = nums[nums[0]];
    while (slow != fast)
    {
      slow = nums[slow];
      fast = nums[nums[fast]];
    }

    fast = 0;
    while (fast != slow)
    {
      fast = nums[fast];
      slow = nums[slow];
    }
    return slow;
  }
  return -1;
}

// Binary search like solution
// 24ms, kind of slow
// https://leetcode.com/discuss/60830/solutions-explanation-space-without-changing-input-array
int findDuplicate(vector<int>& nums) {
  int n = nums.size(), l = 1, r = n - 1;
  while (l < r) {
    int m = l + ((r - l) >> 1);
    int cnt = notGreaterThan(nums, m);
    if (cnt <= m) l = m + 1;
    else r = m;
  } 
  return l;
}
int notGreaterThan(vector<int>& nums, int target) {
  int cnt = 0;
  for (int num : nums)
    if (num <= target)
      cnt++;
  return cnt;
}

int findDuplicate_bad(vector<int>& nums) {
  int n   = nums.size();
 
  long long es = 0, os = 0;
  for(int i=1;i<=n;i++) { 
    if ( i%2==0 ) es += i;
    else          os += i;
  }

  for(auto v:nums) { 
    if ( v%2==0 ) es -= v; 
    else          os -= v;
    if ( es < 0 || os < 0 ) break;
  }

  cout << "# " << es << " " << os << endl;
  if(es==0 && os==0) return 0;
  
  bool even = ( es < 0 || os > 0 );

  for(int i=0, j;i<n;i++){
    if ( ( even && (nums[i]&1)==0) || 
         (!even && (nums[i]&1)==1) ){
      for(int j=i+1;j<n;j++)
        if(nums[i]==nums[j]) 
          return nums[i];
    }
  }
  return 0;
}

int main(){
  vector<int> i1{ 1,1,1,4,5,6,7,8 }; 
  cout << findDuplicate(i1) << " 1" << endl;
  vector<int> i2{ 1,2,2 }; 
  cout << findDuplicate(i2) << " 2" << endl;
  vector<int> i3{ 1,1 }; 
  cout << findDuplicate(i3) << " 1" << endl;
  vector<int> i4{ 1,1,2 }; 
  cout << findDuplicate(i4) << " 1" << endl;
  return 0;
}
