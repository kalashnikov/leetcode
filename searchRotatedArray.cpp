#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

// https://leetcode.com/discuss/22678/revised-binary-search
int search(vector<int>& A, int target) {
  int lo = 0;
  int hi = A.size() - 1;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (A[mid] == target) return mid;

    if (A[lo] <= A[mid]) {
      if (target >= A[lo] && target < A[mid]) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    } else {
      if (target > A[mid] && target <= A[hi]) {
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    }
  }
  return A[lo] == target ? lo : -1;
}

int search2(vector<int>& nums, int target) {
  if(nums.size()==0) return -1;
  if(nums.size()==1) return nums[0]==target ? 0 : -1;

  int n = nums.size();
  int i = 0, j = n-1, idx = 0, idx2 = 0; 
  while(i<j){
    idx  = i + (j-i)/2;
    idx2 = i + (j-i)/2 + 1;
    cout << i << " " << j << " | " << idx << endl;
    if(nums[i]==target)    return i; 
    if(nums[j]==target)    return j; 
    if(nums[idx]==target)  return idx; 
    //if(nums[idx2]==target) return idx2; 

    if ( nums[i] < nums[j] ) {
      if ( nums[idx] < target && nums[j] > target ) { 
        i = idx;
      } else { 
        j = idx;
      }
    } else {
      if ( nums[idx] > nums[i] ) { 
        // pivot at right part 
        if ( nums[idx] < target || nums[j] > target ) {
          i = idx;
        } else { 
          j = idx;
        }
      } else {
        // pivot at left part
        if ( nums[idx] < target && nums[j] > target ) {
          i = idx;
        } else {
          j = idx; 
        }
      }
    }
    //if ( i==j-1 ) break;
  }
  return -1;
}

int main(){
  vector<int> i1 { 4,5,6,7,0,1,2 };
  for(int i=0;i<i1.size();i++){
    cout << "Try: " << i << endl;
    if(search(i1,i1[i])!=i){ 
      cout << i << " fail " << i1[i] << endl;
    }
  }
  vector<int> i2 { 8,0,1,2,4,5,6,7 };
  for(int i=0;i<i2.size();i++){
    cout << "Try: " << i << endl;
    if(search(i2,i2[i])!=i){ 
      cout << i << " fail " << i2[i] << endl;
    }
  }
  vector<int> i3 { 8,9,2,3,4 };
  for(int i=0;i<i3.size();i++){
    cout << "Try: " << i << endl;
    if(search(i3,i3[i])!=i){ 
      cout << i << " fail " << i3[i] << endl;
    }
  }
  vector<int> i4 { 2,3,4,5,6,7,8,9,1 };
  for(int i=0;i<i4.size();i++){
    cout << "Try: " << i << endl;
    if(search(i4,i4[i])!=i){ 
      cout << i << " fail " << i4[i] << endl;
    }
  }
  return 0;
}
