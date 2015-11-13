#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

int findMinHelper(vector<int>& nums, int lo, int hi){ 
  if( lo+1 == hi ) return min(nums[lo],nums[hi]); 

  int lov = nums[lo];
  int hiv = nums[hi];
  int piv = nums[(lo+hi)/2];
  if ( piv==hiv && piv==lov) {
    int v1 = findMinHelper(nums, lo, (lo+hi)/2);
    int v2 = findMinHelper(nums, (lo+hi)/2, hi);
    return min(v1,v2);
  } else if ( (piv >= lov && piv > hiv) ) {
    return findMinHelper(nums, (lo+hi)/2, hi);
  }  else if ( piv <= lov && piv <= hiv ) {
    return findMinHelper(nums, lo, (lo+hi)/2);
  } else {
    return min(nums[lo],nums[hi]);
  }
}

// 153: no duplicate
// 154: allow duplicate
// No difference in time complexity
int findMin2(vector<int>& nums) {
  if(nums.size()==0) return 0;
  if(nums.size()==1) return nums[0];
  // all number is in increasing order except at the boundary point
  for (auto i = 0; i < nums.size()-1; ++i){
    if (nums[i] > nums[i+1]){
      return nums[i+1];
    }
  }
  return nums[0];
}

int findMin(vector<int>& nums) {
  if(nums.size()==0) return 0;
  if(nums.size()==1) return nums[0];
  if(nums.size()==2) return min(nums[0],nums[1]);
  return findMinHelper(nums, 0, nums.size()-1);
}

int main(){

  vector<int> v0 {7,7,0,1,2,4,5,6};
  cout << findMin(v0) << " vs " << findMin2(v0) << endl;

  vector<int> v1 {4,4,5,6,6,7,0,1,1,2};
  cout << findMin(v1) << " vs " << findMin2(v1) << endl;

  vector<int> v2 {6,6,7,0,1,2,4,5};
  cout << findMin(v2) << " vs " << findMin2(v2) << endl;

  vector<int> v3 {0,1,1,2,4,5,6,7};
  cout << findMin(v3) << " vs " << findMin2(v3) << endl;

  vector<int> v4 {1,2,2,4,4,5,6,7};
  cout << findMin(v4) << " vs " << findMin2(v4) << endl;

  vector<int> v5 {3,3,3,1,3};
  cout << findMin(v5) << " vs " << findMin2(v5) << endl;

  vector<int> v9 {3,1,3,3};
  cout << findMin(v9) << " vs " << findMin2(v9) << endl;

  vector<int> v6 {1,1,1};
  cout << findMin(v6) << " vs " << findMin2(v6) << endl;

  vector<int> v7 {1,3,3};
  cout << findMin(v7) << " vs " << findMin2(v7) << endl;

  vector<int> v8 {10,1,10,10,10};
  cout << findMin(v8) << " vs " << findMin2(v8) << endl;

  return 0;
}
