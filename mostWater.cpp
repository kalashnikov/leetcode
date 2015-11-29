#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

int maxArea(vector<int>& height) {
  if ( height.size()<2 ) return 0;
  int ans = 0;
  long area = 0;
  int i = 0, j = height.size()-1;
  while(i<j){
    ans = max(ans,(j-i)*min(height[i],height[j]));
    if(height[i]>height[j]) j--; 
    else  i++;
  }
  return ans;
}

int main(){
  vector<int> i1 { 1,2,7,3,5,9,4 }; 
  cout << maxArea(i1) << " 21" << endl; 
  vector<int> i2 { 1,2,4,3 }; 
  cout << maxArea(i2) << " 4" << endl; 
  return 0;
}
