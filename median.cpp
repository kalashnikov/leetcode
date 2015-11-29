#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

int partition(vector<int>& nums, int lo, int hi) {
  int piv = nums[lo+(hi-lo)/2];
  while(lo<=hi){
    while(nums[lo]<piv) lo++;
    while(piv<nums[hi]) hi--;
    if ( lo <= hi ) swap(nums[lo++],nums[hi--]);
  }
  return lo;
}

void ksort(vector<int>&nums, int lo, int hi){
  if (nums.size()<2) return ;
  int piv = partition(nums,lo,hi);
  if ( lo  < piv-1 ) ksort(nums, lo, piv-1);
  if ( piv < hi    ) ksort(nums, piv,   hi);
}

int findMedian(vector<int>& nums){
  if(nums.size()==0) return -1;
  if(nums.size()==1) return nums[0];
  int n = nums.size()/2, lo = 0, hi = nums.size()-1;
  int piv = partition(nums,0,hi);
  while(piv!=n){
    if(piv>n) {
      hi = piv-1;
    } else {
      lo = piv;
    }
    piv = partition(nums,lo,hi);
  }
  return nums[piv];
}

// https://leetcode.com/discuss/41621/very-concise-iterative-solution-with-detailed-explanation
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
  int N1 = nums1.size();
  int N2 = nums2.size();
  
  // Make sure A2 is the shorter one.
  if (N1 < N2) return findMedianSortedArrays(nums2, nums1);

  // If A2 is empty
  if (N2 == 0) return ((double)nums1[(N1-1)/2] + (double)nums1[N1/2])/2; 

  int lo = 0, hi = N2 * 2;
  while (lo <= hi) {
    int mid2 = (lo + hi) / 2;   // Try Cut 2 
    int mid1 = N1 + N2 - mid2;  // Calculate Cut 1 accordingly

    // Get L1, R1, L2, R2 respectively
    double L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1-1)/2]; 
    double L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2-1)/2];
    double R1 = (mid1 == N1 * 2) ? INT_MAX : nums1[(mid1)/2];
    double R2 = (mid2 == N2 * 2) ? INT_MAX : nums2[(mid2)/2];

    // A1's lower half is too big; need to move C1 left (C2 right)
    if (L1 > R2) lo = mid2 + 1;    
    // A2's lower half too big; need to move C2 left.
    else if (L2 > R1) hi = mid2 - 1;   
    // Otherwise, that's the right cut.
    else return (max(L1,L2) + min(R1, R2)) / 2; 
  }
  return -1;
} 


int main(){
  //vector<int> v{5, 6, 4, 3, 2, 6, 7, 9, 3,10};
  //nth_element(v.begin(), v.begin() + v.size()/2, v.end());
  //cout << "The median is " << v[v.size()/2] << endl;
  //ksort(v, 0, v.size()-1);
  //cout << findMedian(v) << endl;
  //for(auto vv:v) cout << vv << " "; cout << endl; 

  vector<int> i1 { 2,3,3,4,6  }; 
  vector<int> i2 { 5,6,7,9,10 }; 
  cout << findMedian(i1, i2) << endl;
  return 0;
}
