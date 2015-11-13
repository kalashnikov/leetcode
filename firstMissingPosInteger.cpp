#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

int firstMissingPositive2(vector<int>& nums) {
  if(nums.size()==0) return 1;
  int m = 1;
  for(int i=0;i<nums.size();i++){
    m = max(m,nums[i]); 
  }

  int size = m/32 + 1;
  int bit[size];
  memset(bit, 0, sizeof(bit));
  for(int i=0;i<nums.size();i++){
    if ( nums[i]<1 ) continue;
    bit[(nums[i]-1)/32] |=  1 << (nums[i]-1);
  }

  for(int i=0;i<size;i++){
    for(int j=0;j<32;j++){
      if( !( bit[i] & (1 << j) ) ){
        return (i*32+j+1);
      }
    }
  }
  return 1;
}

int firstMissingPositive(vector<int>& nums) {
  if(nums.size()==0) return 1;
  int n = nums.size();
  for(int i=0;i<n;i++){
    while(nums[i]>0 && nums[i]<=n && nums[i]!=nums[nums[i]-1])
      swap(nums[i], nums[nums[i]-1]);
  }

  for(int i=0;i<nums.size();i++){
    if (nums[i]!=i+1)
      return i+1;
  }
  return 1;
}

int main(){
  vector<int> i1 {1,2,0};
  vector<int> i2 {3,4,-1,1};
  vector<int> i3 {99,94,96,11,92,5,91,89,57,85,66,63,84,81,79,61,74,78,77,30,64,13,58,18,70,69,51,12,32,34,9,43,39,8,1,38,49,27,21,45,47,44,53,52,48,19,50,59,3,40,31,82,23,56,37,41,16,28,22,33,65,42,54,20,29,25,10,26,4,60,67,83,62,71,24,35,72,55,75,0,2,46,15,80,6,36,14,73,76,86,88,7,17,87,68,90,95,93,97,98};
  cout << firstMissingPositive(i1) << endl;
  cout << firstMissingPositive(i2) << endl;
  cout << firstMissingPositive(i3) << endl;
  return 0;
}
