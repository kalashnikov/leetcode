#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <sstream>

using namespace std;

// https://leetcode.com/discuss/40159/simply-0ms-c-solution
string get_range(int start, int end)
{
  return start==end? to_string(start) : to_string(start)+"->"+to_string(end);
}
vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
  vector<string> result;
  int pre = lower-1;
  for(int i =0; i <= nums.size(); i++)
  {
    int cur = (i==nums.size()? upper+1:nums[i]);
    if(cur-pre>=2)
      result.push_back(get_range(pre+1,cur-1));
    pre = cur;
  }
  return result;
}

vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
  if(nums.size()==0) {
    stringstream ss;
    if(lower!=upper) 
      ss << lower << "->" << upper;
    else 
      ss << lower;
    return vector<string>({ss.str()});
  }

  vector<string> ans;
  if(nums[0]>lower) { 
    string ss = to_string(lower); 
    if(lower!=nums[0]-1)  
      ss += "->" + to_string(nums[0]-1);
    ans.emplace_back(ss);
  }

  int last = nums[0];
  for(int i=1;i<nums.size();i++){
    if(last+1!=nums[i]){
      string ss = to_string(last+1); 
      if(last+1!=nums[i]-1)
        ss += "->" + to_string(nums[i]-1);
      ans.emplace_back(ss);
    }
    last = nums[i];
  }
  
  if(last+1<=upper){
    string ss = to_string(last+1); 
    if(last+1<=upper-1) 
      ss += "->" + to_string(upper);
    ans.emplace_back(ss);
  }

  return ans;
}

int main(){
  vector<int> i1 { 0, 1, 3, 50, 75 };
  auto a1 = findMissingRanges(i1, 0, 99);
  for(auto v:a1) cout << v << " "; cout << endl;
  vector<int> i2 {-1};
  auto a2 = findMissingRanges(i2, -1, -1);
  for(auto v:a2) cout << v << " "; cout << endl;
  vector<int> i3 { 7};
  auto a3 = findMissingRanges(i3,  0,  9);
  for(auto v:a3) cout << v << " "; cout << endl;
  return 0;
}
