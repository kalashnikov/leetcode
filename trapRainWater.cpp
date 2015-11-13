#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

int trap(vector<int>& height) {
  int l = 0, r = height.size()-1, level = 0, water = 0;
  while (l < r) {
    int lower = height[height[l] < height[r] ? l++ : r--];
    level = max(level, lower);
    cout << water << " + " << level << " - " << lower << " = " << (water+level-lower) << " | " << l << " " << r << endl;
    water += level - lower;
  }
  return water;
}

int trap2(vector<int>& height) {
  if ( height.size()==0 ) return 0;
  int ans = 0;
  int lastmax = height[0], trap = 0; 
  int backtrack = 0;
  for(int i=1;i<height.size();i++){
    if ( height[i] >= lastmax ) {
      ans += trap;
      lastmax = height[i];
      trap = 0;
      backtrack = i;
    } else {
      trap += lastmax - height[i];
    }
  }
  
  lastmax = 0, trap = 0;
  for(int i=height.size()-1;i>=backtrack;i--){
    if ( height[i] >= lastmax ) {
      ans += trap;
      lastmax = height[i];
      trap = 0;
    } else {
      trap += lastmax - height[i];
    }
  }
  return ans;
}

int main(){
  vector<int> i1 {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << trap(i1) << endl;
  vector<int> i2 {2,0,2};
  cout << trap(i2) << endl;
  return 0;
}
