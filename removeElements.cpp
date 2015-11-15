#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

int removeElement(vector<int>& nums, int val) {
  if(nums.size()==0) return 0;
  if(nums.size()==1) return nums[0]==val ? 0 : 1;
  int i = 0, j = nums.size()-1;
 
  i = 0, j = nums.size()-1;
  while(i<j){
    while(i<j && nums[i]!=val ) i++;
    if ( i==j && nums[i]==val ) break;
    while(i<j && nums[i]==val ) swap(nums[i],nums[j--]);
    i++; 
  }
  while(i<nums.size() && nums[i]!=val) i++;
  return  (nums[i-1]==val) ? i-1 : i; 
}

int main(){
  vector<int> i1 { 1,2,2,4,2,5 }; 
  int n = removeElement(i1,2);
  for(int i=0;i<n;i++) cout << i1[i] << " "; cout <<  " | " << n << endl;
  vector<int> i2 { 4,5 }; 
  int n2 = removeElement(i2,5);
  for(int i=0;i<n2;i++) cout << i2[i] << " "; cout << " | " << n2 << endl;
  vector<int> i3 { 1 }; 
  int n3 = removeElement(i3,1);
  for(int i=0;i<n3;i++) cout << i3[i] << " "; cout <<  " | " << n3 << endl;
  vector<int> i4 { 2,3,3 }; 
  int n4 = removeElement(i4,3);
  for(int i=0;i<n4;i++) cout << i4[i] << " "; cout << " | " << n4 << endl;
  vector<int> i5 { 4,5 }; 
  int n5 = removeElement(i5,4);
  for(int i=0;i<n5;i++) cout << i5[i] << " "; cout << " | " << n5 << endl;
  vector<int> i6 { 2,3,3 }; 
  int n6 = removeElement(i6,2);
  for(int i=0;i<n6;i++) cout << i6[i] << " "; cout << " | " << n6 << endl;
  vector<int> i7 { 3,3 }; 
  int n7 = removeElement(i7,5);
  for(int i=0;i<n7;i++) cout << i7[i] << " "; cout << " | " << n7 << endl;
  return 0;
}
