#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <sstream>
#include <cstdlib>

using namespace std;

vector<string> summaryRanges(vector<int>& nums) {
  int i = 0, j = 0, range = 0;
  vector<string> ans;

  if ( nums.size()==0 ) return ans;

  while ( i<nums.size() ) {
    range = nums[i];
    j = i+1; 
    while ( j<nums.size() ) {
      if ( nums[j]-1!=nums[j-1] ) 
        break;
      else 
        range = nums[j];
      j++;
    }
    //cout << nums[i] << " r: " << range << endl;
    stringstream ss;
    if ( range==nums[i] ) { 
      ss << range;
      i++;
    } else { 
      ss << nums[i] << "->" << range; 
      i = j;
    }
    ans.push_back(ss.str());
  }

  return ans;
}

int main(){

  vector<int> v0 {1};
  auto r0 = summaryRanges(v0);
  for(auto v:r0) 
    cout << v << " "; 
  cout << endl;

  vector<int> v1 {0,1,2,4,5,7};
  auto r1 = summaryRanges(v1);
  for(auto v:r1) 
    cout << v << " "; 
  cout << endl;

  return 0;
}
