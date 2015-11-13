#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target) {
  map<int,int> m;
  vector<int> vec;
  for( int i=0;i<nums.size();i++){
    if ( m.find(target-nums[i])!=m.end()) { 
      int other = m[target-nums[i]];
      if ( other > i ) {
        vec.push_back(i+1);
        vec.push_back(other+1);
      } else { 
        vec.push_back(other+1);
        vec.push_back(i+1);
      }
      return vec;
    }
    m.insert(make_pair(nums[i],i));
  }
  return vec;
}

int main(){
  vector<int> vec1{2,7,11,15};
  auto result1= twoSum(vec1, 9);
  for(auto v : result1) 
    cout << v << " ";
  cout << endl;
  vector<int> vec2{3,2,4};
  auto result2= twoSum(vec2, 6);
  for(auto v : result2) 
    cout << v << " ";
  cout << endl;
  return 0;
}
