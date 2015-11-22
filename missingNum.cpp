#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

// Limitation: Only 0, 1, 2, ..., n
// 0, 1, 2, ..., n+1 will fail
// https://leetcode.com/discuss/53802/c-solution-using-bit-manipulation
int missingNumber(vector<int>& nums) {
  int result = nums.size();
  int i=0;

  for(int num:nums){
    result ^= num;
    result ^= i;
    i++;
  }

  return result;
}

// Using Sum
int missingNumber(vector<int>& nums) {
  int iLength = nums.size();
  if(nums[0])
    return 0;
  for(int iIndex;iIndex < iLength-1;iIndex++)
  {
    if(1!=nums[iIndex+1]-nums[iIndex])
      return nums[iIndex]+1;
  }
  return nums[iLength-1]+1;
}

int missingNumber1(vector<int>& nums) {
  if(nums.size()==0) return 0;
  for(int i=0;i<nums.size();i++)
    while(nums[i]!=i && nums[i]<nums.size()) 
      swap(nums[i],nums[nums[i]]);
 
  for(int i=0;i<nums.size();i++)
    if(nums[i]!=i)
      return i;
  return nums.size();
}

int main(){
  vector<int> i1 {2,0,6,3,1};
  cout << missingNumber(i1) << " 4" << endl;
  return 0;
}
