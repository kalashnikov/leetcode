#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
  if ( nums.size()==0 ) return 0;
  if ( nums.size()==1 ) {
    if ( target > nums[0] ) return 1;
    else return 0;
  }
  int i = 0, j = nums.size()-1, pos;
  while(i<j){
    pos = i + (j-i)/2;
    if ( nums[pos]==target ) { 
      return pos;
    } else if ( nums[pos] > target ) {
      j = pos;
    } else {
      i = pos+1;
    }
  }
  if (nums[i]<target) i++;
  return i;
}

int main(){
  vector<int> v1 {1,3,5,6}; 
  cout << searchInsert(v1, 5) << endl;
  vector<int> v2 {1,3,5,6};
  cout << searchInsert(v2, 2) << endl;
  vector<int> v3 {1,3,5,6};
  cout << searchInsert(v3, 7) << endl;
  vector<int> v4 {1,3,5,6};
  cout << searchInsert(v4, 0) << endl;
  vector<int> v5 {1,3};
  cout << searchInsert(v5, 2) << endl;
  return 0;
}
