#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

// https://leetcode.com/discuss/22678/revised-binary-search
int search_unique(vector<int>& A, int target) {
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

// Duplicate 
bool search(vector<int>& A, int target) {
  int lo = 0;
  int hi = A.size() - 1;
  while (lo < hi) {
    int mid = (lo + hi) / 2;
    if (A[mid] == target) return true;

    if (A[lo] < A[mid]) {
      if (target >= A[lo] && target < A[mid]) {
        hi = mid - 1;
      } else {
        lo = mid + 1;
      }
    } else if (A[lo] > A[mid]){
      if (target > A[mid] && target <= A[hi]) {
        lo = mid + 1;
      } else {
        hi = mid - 1;
      }
    } else {
      // Main difference. 
      // When A[lo]==A[mid], we can only advance left by one.
      // Worst case: O(n)
      lo++; 
    }
  }
  return A[lo] == target ? true : false;
}

int main(){
  //vector<int> i1 { 4,5,6,7,0,1,2 };
  //for(int i=0;i<i1.size();i++){
  //  cout << "Try: " << i << endl;
  //  if(search(i1,i1[i])!=i){ 
  //    cout << i << " fail " << i1[i] << endl;
  //  }
  //}
  //vector<int> i2 { 8,0,1,2,4,5,6,7 };
  //for(int i=0;i<i2.size();i++){
  //  cout << "Try: " << i << endl;
  //  if(search(i2,i2[i])!=i){ 
  //    cout << i << " fail " << i2[i] << endl;
  //  }
  //}
  //vector<int> i3 { 8,9,2,3,4 };
  //for(int i=0;i<i3.size();i++){
  //  cout << "Try: " << i << endl;
  //  if(search(i3,i3[i])!=i){ 
  //    cout << i << " fail " << i3[i] << endl;
  //  }
  //}
  //vector<int> i4 { 2,3,4,5,6,7,8,9,1 };
  //for(int i=0;i<i4.size();i++){
  //  cout << "Try: " << i << endl;
  //  if(search(i4,i4[i])!=i){ 
  //    cout << i << " fail " << i4[i] << endl;
  //  }
  //}
  cout << "######" << endl;
  vector<int> i5 { 1,3,1,1,1 };
  for(int i=0;i<i5.size();i++){
    cout << "Try: " << i << endl;
    if(!search(i5,i5[i])){ 
      cout << i << " fail " << i5[i] << endl;
    }
  }
  return 0;
}
