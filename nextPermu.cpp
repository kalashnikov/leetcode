#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <utility>

using namespace std;

// 123, 132, 213, 231, 312, 321, 123
void nextPermutation(vector<int>& nums) {
  if ( nums.size() < 2 ) return;
  int tmp;
  for( int i=nums.size()-2;i>=0;i-- ) { 
    if ( nums[i] < nums[i+1] ) { 
      if ( i == nums.size()-2 ) {
        tmp = nums[i]; 
        nums[i] = nums[i+1];
        nums[i+1] = tmp; 
        return;
      } else {
        int idx = nums.size()-1, small = INT_MAX;
        // Find the smallest number larger than num[i]
        for( int j=i+1;j<nums.size();j++ ) {
          if ( nums[j] > nums[i] && nums[j] < small ) {
            small = nums[j];
            idx = j;
          }
        }
        // Swap the nums and then sort others left in ascending order
        tmp = nums[i]; 
        nums[i] = nums[idx];
        nums[idx] = tmp;
        sort(nums.begin()+i+1, nums.end());
        return;
      }
    }
  }
  // sort in ascending order
  sort(nums.begin(),nums.end());
  return;
}

int main(){
  vector<int> c1{1,2,3};
  for(auto v:c1) cout << v << " ";
  cout << endl;
  for (int i=0;i<6;i++) { 
    nextPermutation(c1);
    for(auto v:c1) cout << v << " ";
    cout << endl;
  }

  vector<int> c3{1,1,5};
  nextPermutation(c3);
  for(auto v:c3) cout << v << " ";
  cout << endl;

  return 0;
}
