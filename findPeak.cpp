#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

int findPeakElement(vector<int>& nums) {
  int lo = 0, hi = nums.size(), piv;
  while(lo<hi){
    piv = lo + (hi-lo)/2;
    if( ( piv>0 && nums[piv]>nums[piv-1] ) &&
        ( piv<nums.size()-1 && nums[piv]>nums[piv+1] ) ) 
        break;
    
    if( piv>0 && nums[piv]>nums[piv-1] ) lo = piv+1;
    else hi = piv;
  }

  return piv;
}

int main(){
  vector<int> i1 { 10,2,3,4,9,1 };
  cout << findPeakElement(i1) << " 2" << endl;
  return 0;
}
