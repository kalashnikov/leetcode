#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

int partition(vector<int>& nums, int lo, int hi){
  int pivot = nums[lo+(hi-lo)/2];
  cout << "Piv: " << pivot << "," << (lo+(hi-lo)/2) << " | " << lo << " " << hi << endl; 
  while(lo<=hi){
    while(nums[lo]<pivot) lo++;
    while(nums[hi]>pivot) hi--;
    if(lo<=hi){
      swap(nums[lo++],nums[hi--]);
    }
  }
  return lo;
}

// Broken ... fxxk
int findKthLargest3(vector<int>& nums, int k) {
  if(nums.size()==0) return -1;

  int lo = 0, hi = nums.size()-1; 
  int t   = nums.size()-k; 
  int idx = partition(nums, lo, hi);
  
  cout << t << " " << idx << " | " << lo << " " << hi << " | "; 
  for(auto v:nums) cout << v << " "; cout << endl;
  
  while( ( lo<=idx-1 || idx <= hi ) && idx!=t ){
    if ( idx>t  ) { 
      hi = idx - 1;
    } else {
      lo = idx + 1;
    }
    idx = partition(nums, lo, hi);
    if(lo==hi) idx = lo;

    cout << t << " " << idx << " | " << lo << " " << hi << " | "; 
    for(auto v:nums) cout << v << " "; cout << endl;
  }
  return nums[idx];
}

// https://leetcode.com/discuss/45366/c-using-quick-selection-clean-code 
int findKthLargest_golden(vector<int>& nums, int k) {
    const int size_n = nums.size();
    int left = 0, right = size_n;
    while (left < right) {
        int i = left, j = right - 1, povit = nums[left];
        while(i <= j) {
            while (i <= j && nums[i] >= povit) i++;
            while (i <= j && nums[j] < povit) j--;
            if (i < j)
                swap(nums[i++], nums[j--]);
        }
        swap(nums[left], nums[j]);
        if (j == k - 1) return nums[j];
        if (j < k - 1) left = j + 1;
        else right = j;
    }
}

int findKthLargest2(vector<int>& nums, int k){
  std::nth_element(nums.begin(), nums.begin() + (nums.size()-k), nums.end());
  return nums[nums.size()-k];
}

int findKthLargest(vector<int>& nums, int k){
  const int sz = nums.size();
  int lo = 0, hi = sz;
  while(lo < hi) {
    int i = lo, j = hi-1, pivot = nums[lo]; 
    while(i<=j){
      while(i<=j && nums[i] >= pivot) i++;
      while(i<=j && nums[j]  < pivot) j--;
      if(i<=j)
        swap(nums[i++],nums[j--]);
    }
    swap(nums[lo], nums[j]);
    if(j==k-1) return nums[j];
    if(j <k-1) lo = j+1;
    else       hi = j;
  }
}

int main(){
  vector<int> i0 { 1 };
  cout << findKthLargest(i0, 1) << " 1" << endl;
  vector<int> i1 { 3,2,1,5,6,4,3 };
  cout << findKthLargest(i1, 2) << " 5" << endl;
  vector<int> i2 { -1,2,0 };
  cout << findKthLargest(i2, 2) << " 0" << endl;
  vector<int> i3 { 3,2,3,1,2,4,5,5,6,7,7,8,2,3,1,1,1,10,11,5,6,2,4,7,8,5,6 };
  cout << findKthLargest(i3, 2) << " 10" << endl;
  vector<int> i4 { 3,2,3,1,2,4,5,5,6 };
  cout << findKthLargest(i4, 1) << " 6" << endl;
  vector<int> i5 { 3,3,3,3,3,3,3,3 };
  cout << findKthLargest(i5, 8) << " 3" << endl;
  vector<int> i6 { 3,2,3,1,2,4,5,5,6 };
  cout << findKthLargest(i6, 9) << " 1" << endl;
  return 0;
}
