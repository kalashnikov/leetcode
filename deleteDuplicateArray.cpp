#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

int removeDuplicates(vector<int>& nums) {
  if ( nums.size()<2 ) return nums.size(); 
  int i = 1, l = 0; 
  // l points to current unique pos
  // i as scan pointer, and swap/save unique pos with l+1 pos
  // l pointer is slow than i, so i should reach end of array first.
  while(i<nums.size()){
    if ( nums[i]!=nums[l] ) {
      swap(nums[i],nums[l+1]);
      l++;
    }
    i++;
  }
  return l+1;
}

int main(){
  vector<int> i1 { 1,2,2,4,4,5,5,5,6 }; 
  int n = removeDuplicates(i1);
  for(int i=0;i<n;i++) cout << i1[i] << " "; cout <<  " | " << n << endl;
  vector<int> i4 { 2,3,3 }; 
  int n4 = removeDuplicates(i4);
  for(int i=0;i<n4;i++) cout << i4[i] << " "; cout << " | " << n4 << endl;
  vector<int> i7 { 3,3 }; 
  int n7 = removeDuplicates(i7);
  for(int i=0;i<n7;i++) cout << i7[i] << " "; cout << " | " << n7 << endl;
  return 0;
}
