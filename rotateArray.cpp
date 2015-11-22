#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

// https://leetcode.com/discuss/26501/3-lines-of-c-in-one-pass-using-swap
// O(n) with O(1) space using swap : 28ms 
void rotate(vector<int>& nums, int k) {
  int start = 0, n = nums.size();
  for (; k %= n; n -= k, start += k){
    cout << "### start:"<< start << ", n:" << n << " : ";
    for (int i = 0; i < k; i++)
      // first k item swap with last k items 
      swap(nums[start + i], nums[start + n - k + i]);
    for(auto v:nums) cout << v << " "; cout << endl;
  }
}

// O(n) with O(n) space : 24ms
void rotate2(vector<int>& nums, int k) {
  if(nums.size()<2) return;
  k = k%nums.size();
  vector<int> t(nums.size(),0);
  int idx = 0;
  for(int i=nums.size()-k;i<nums.size();i++) t[idx++] = nums[i];
  for(int i=0;i<nums.size()-k;i++) t[idx++] = nums[i];
  swap(nums,t); t.clear();
  return ;
}

int main(){
  vector<int> i1 { 1,2,3,4,5,6,7 };
  rotate(i1,10);
  for(auto v:i1) cout << v << " "; cout << endl;
  return 0;
}
