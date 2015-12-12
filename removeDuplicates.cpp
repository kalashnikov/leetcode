#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

// https://leetcode.com/discuss/42348/3-6-easy-lines-c-java-python-ruby
int removeDuplicates(vector<int>& nums) {
  int i = 0;
  for (int n : nums)
    if (i < 1 || n > nums[i-1])
      nums[i++] = n;
  return i;
}

int removeDuplicates2(vector<int>& nums) {
  if(nums.size()<3) return nums.size();

  int n = nums.size();
  int i = 0, j = 0, cnt = 0;
  vector<int> tmp(n, 0);

  while(i<n && j<n){
    if(cnt<2){
      if(j==0 || nums[i]==tmp[j-1]) 
        cnt++; 
      else  
        cnt = 1;
      tmp[j]=nums[i];
      i++;j++; 
    } else {
      while(nums[i]==tmp[j-1]) i++;
      cnt = 0;
    }
    cout << cnt << ": " << i << " " << j << " | "; for(auto v:tmp) cout << v << " "; cout << endl;
  }
  swap(nums, tmp); 
  return j;
}

int main(){
  //vector<int> i1 { 1,1,1,1,2,2,2,3,3,3,3,3 };
  //vector<int> i1 { 1,1,1,1,2,2,2,2,3,3,3,4 };
  vector<int> i1 { 1,1,1,1,2,2,2,2,3 };
  int cnt = removeDuplicates(i1);
  for(int i=0;i<cnt;i++) 
    cout << i1[i] << " "; 
  cout << endl;
  return 0;
}
