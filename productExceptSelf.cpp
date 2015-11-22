#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

// 60ms 
vector<int> productExceptSelf(vector<int>& nums) {
  vector<int> ans(nums.size(),1);
  // Forward scan and save product so far
  for(int i=0,pro=1;i<nums.size();pro*=nums[i++]){
    ans[i] *= pro; 
  }
  // Backward scan and save product so far
  for(int i=nums.size()-1, pro=1;i>=0;pro*=nums[i--]){
    ans[i] *= pro; 
  }
  return ans;
}

int main(){
  vector<int> i1{1,2,3,4};
  auto a1 = productExceptSelf(i1);
  for(auto v:a1) cout << v << " "; cout << endl;
  return 0;
}
