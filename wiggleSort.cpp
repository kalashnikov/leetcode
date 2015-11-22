#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

void wiggleSort(vector<int>& nums) {
  if(nums.size()<2) return;
  if(nums.size()<3) {
    if(nums[0]>nums[1]) 
      swap(nums[0],nums[1]);
    return;
  }

  // size >= 3
  int maxIdx = -1, maxVal = INT_MIN, n = nums.size();
  for(int i=1;i<n;i+=2){
    maxIdx = i, maxVal = nums[i];
    if(nums[i-1]>maxVal) { maxIdx = i-1; maxVal = nums[i-1]; } 
    if(i+1<n && nums[i+1]>maxVal) { maxIdx = i+1; maxVal = nums[i+1]; } 
    if(maxIdx!=i) swap(nums[maxIdx],nums[i]);
  }

  return;
}

int main(){
  vector<int> i1 { 5,4,7,1,6,3 }; 
  wiggleSort(i1);
  for(auto v:i1) cout << v << " "; cout << endl;
  return 0;
}
