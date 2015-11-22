#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
  if ( n == 0 ) return ;
  if ( m == 0 ) { swap(nums1,nums2); return; } 
  int i = m+n-1, idx1 = m-1, idx2 = n-1;
  while(i>=0 && idx2>=0){
    if(idx1>=0&&nums1[idx1]>nums2[idx2]) nums1[i--]=nums1[idx1--];
    else nums1[i--]=nums2[idx2--];
  }
  return;
}

int main(){
  vector<int> v1 { 2,3,5,7,9,0,0,0,0 };
  vector<int> v2 { 1,4,6,8 };
  merge(v1, 5, v2, v2.size() );
  for(auto v:v1) cout << v << " "; cout << endl;
 
  vector<int> v3 { -1,0,0,3,3,3,0,0,0 };
  vector<int> v4 { 1,2,2 };
  merge(v3, 6, v4, v4.size() );
  for(auto v:v3) cout << v << " "; cout << endl;
  
  vector<int> v5 { 4,5,6,0,0,0 };
  vector<int> v6 { 1,2,3 };
  merge(v5, 3, v6, v6.size() );
  for(auto v:v5) cout << v << " "; cout << endl;
  return 0;
}
