#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

int helper(vector<pair<int,int>> l, vector<pair<int,int>>& h){
  if ( l.size()==0 ) { 
    int sum = 0;
    for(auto v:h){  
      sum+=v.first;
      cout << v.first << "(" << v.second << ") ";
    }
    cout << " | sum:" << sum << endl;
    return sum;
  } else {
    auto v = l.back(); l.pop_back();
    bool ok = true;
    for(auto vv:h) { 
      if ( abs(vv.second - v.second)==1 ){ 
        ok = false;
        break;
      }
    }
    int sum1 = helper(l, h); // no include this one
    if(!ok) return sum1; 
    h.push_back(v);
    int sum2 = helper(l, h);
    h.pop_back();
    return max(sum1,sum2); // include this one
  }
}

bool cmp(const pair<int,int>& a, const pair<int,int>& b){
  return a.first < b.first;
}

int rob2(vector<int>& nums) {
  if(nums.size()==0) return 0;
  if(nums.size()==1) return nums[0];
  vector<pair<int, int>> h, all;
  for(int i=0;i<nums.size();i++)
    all.push_back({nums[i], i});
  //sort(all.begin(),all.end(),cmp);
  return helper(all, h);
}

bool cmp2(const pair<int,int>& a, const pair<int,int>& b){
  return ( a.first > b.first ) ;
}

int rob_not_good(vector<int>& nums) {
  if(nums.size()==0) return 0;
  if(nums.size()==1) return nums[0];
  bool debug = true;
  vector<pair<int, int>> h, all;
  for(int i=0;i<nums.size();i++)
    all.push_back({nums[i], i});
  sort(all.begin(),all.end(),cmp2);
  if ( debug ) for(auto v:all) cout << v.first << "(" << v.second << ") ";
  if ( debug ) cout << endl;
 
  set<int> s { all[0].second } ;
  int ans = all[0].first;
  if ( debug ) cout << "Sum1: " << all[0].first << "(" << all[0].second << ") ";
  for(int i = 1;i<all.size();i++){
    if ( s.count(all[i].second-1) || 
         s.count(all[i].second+1) ) continue;
    ans += all[i].first;
    s.insert(all[i].second);
    if ( debug ) cout << all[i].first << "(" << all[i].second << ") ";
  }
  if ( debug ) cout << endl;
 
  s.clear(); s.insert(all[1].second);
  int sum2 = all[1].first;
  if ( debug ) cout << "Sum2: " << all[1].first << "(" << all[1].second << ") ";
  for(int i = 2;i<all.size();i++){
    if ( s.count(all[i].second-1) || 
        s.count(all[i].second+1) ) continue;
    sum2 += all[i].first;
    s.insert(all[i].second);
    if ( debug ) cout << all[i].first << "(" << all[i].second << ") ";
  }
  if ( debug ) cout << endl;
  if ( sum2 > ans ) ans = sum2;

  return ans;
}

//bool cmp3(const pair<int,int>& a, const pair<int,int>& b){
//  return ( a.first > b.first ) ;
//}
//
//int rob3(vector<int>& nums) {
//  if(nums.size()==0) return 0;
//  if(nums.size()==1) return nums[0];
//  bool debug = true;
//  multiset<pair<int, int>, cmp3> all;
//  for(int i=0;i<nums.size();i++)
//    all.insert({nums[i], i};
//
//  if ( debug ) for(auto v:all) cout << v.first << "(" << v.second << ") ";
//  if ( debug ) cout << endl;
//
//  int ans = all.begin()->first;
//  set<int> cur{all.begin()->second}; // holding idx
//  all.erase(all.begin()); 
//  while(all.size()){
//    while(s.count(all.begin()->second+1) || 
//          s.count(all.begin()->second-1) )  all.erase(all.begin()); 
//    ans += all.begin()->first;
//    cur.insert(all.begin()->second);
//    all.erase(all.begin()); 
//  }
//
//  return ans;
//}

// https://leetcode.com/discuss/30079/c-1ms-o-1-space-very-simple-solution 
// Maintain two max value. One for even and another for odd. 
int rob(vector<int>& nums) { 
  int n = nums.size(), pre = 0, cur = 0;
  for (int i = 0; i < n; i++) {
    int temp = max(pre + nums[i], cur);
    pre = cur;
    cur = temp;
  }
  return cur;
}

int main(){

  vector<int> i1{5,6,2,3,5,1,4};
  cout << rob(i1) << " ";
  cout << rob2(i1) << endl << endl;
  
  vector<int> i2{8,2,8,9,2};
  cout << rob(i2) << " ";
  cout << rob2(i2) << endl << endl;
  
  vector<int> i3{8,9,9,4,10,5,6,9,7,9};
  cout << rob(i3) << " ";
  cout << rob2(i3) << endl;
  return 0;
}
