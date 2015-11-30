#include <iostream>
#include <vector>
#include <set>
#include <list>
#include <iterator>

using namespace std;

struct cmp {
  bool operator()(const pair<int,int>& a,const pair<int,int>& b){
    if(a.first > b.first) return true;
    else if ( a.first < b.first ) return false; 
    else return a.second > b.second;
  }
};

// 164ms 
vector<int> maxSlidingWindow2(vector<int>& nums, int k) {
  vector<int> ans;
  if(k==0||nums.size()==0) return ans;
  multiset<pair<int,int>, cmp> s;
  int i = 0;
  
  for(i=0;i<k;i++) s.insert({nums[i],i}); 
  ans.push_back(s.begin()->first); 
  
  //for(auto v:s) cout << v << " "; cout << endl;
  for(;i<nums.size();i++){
    s.insert({nums[i],i});
    s.erase({nums[i-k],i-k});
    ans.push_back(s.begin()->first); 
  }
  return ans; 
}

// 88ms, beats 95.42%
// Lesson: Avoid data structure if we don't need it.
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
  vector<int> ans;
  if(k==0||nums.size()==0) return ans;

  // Get initial max value
  int idx  = 0, maxv = nums[0];
  for(int i=1;i<k;i++){
    // Keep update the max value 
    // and update idx if we got same value
    if(maxv<=nums[i]) {
      maxv = nums[i]; 
      idx  = i;
    }
  }
  ans.push_back(maxv); 
  
  for(int i=k;i<nums.size();i++){
    if(maxv<=nums[i]) {
      maxv = nums[i]; 
      idx  = i;
    } 

    if(idx==i-k) {
      // Need scan
      idx  = idx+1;
      maxv = nums[idx];
      for(int j=idx+1;j<=i;j++){
        if(nums[j]>=maxv) { 
          maxv = nums[j]; 
          idx  = j;
        }
      }
    }
    ans.push_back(maxv); 
  }
  return ans; 
}

int main(){
  vector<int> i1 {1,3,-1,-3,5,3,6,7};
  auto a1 = maxSlidingWindow(i1, 3);
  for(auto v:a1) cout << v << " "; cout << endl;
  
  vector<int> i2 {-7,-8,7,5,7,1,6,0};
  auto a2 = maxSlidingWindow(i2, 4);
  for(auto v:a2) cout << v << " "; cout << endl;
  return 0;
}
