#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// https://leetcode.com/discuss/67417/my-16ms-c-code
vector<vector<int>> fourSum(vector<int>& nums, int target) {
  vector<vector<int>> total;
  int n = nums.size();
  if(n<4)  return total;
  sort(nums.begin(),nums.end());
  for(int i=0;i<n-3;i++)
  {
    if(i>0&&nums[i]==nums[i-1]) continue;
    if(nums[i]+nums[i+1]+nums[i+2]+nums[i+3]>target) break;
    if(nums[i]+nums[n-3]+nums[n-2]+nums[n-1]<target) continue;
    for(int j=i+1;j<n-2;j++)
    {
      if(j>i+1&&nums[j]==nums[j-1]) continue;
      if(nums[i]+nums[j]+nums[j+1]+nums[j+2]>target) break;
      if(nums[i]+nums[j]+nums[n-2]+nums[n-1]<target) continue;
      int left=j+1,right=n-1;
      while(left<right){
        int sum=nums[left]+nums[right]+nums[i]+nums[j];
        if(sum<target) left++;
        else if(sum>target) right--;
        else{
          total.push_back(vector<int>{nums[i],nums[j],nums[left],nums[right]});
          do{left++;}while(nums[left]==nums[left-1]&&left<right);
          do{right--;}while(nums[right]==nums[right+1]&&left<right);
        }
      }
    }
  }
  return total;
}

struct four {
  int a;
  int b;
  int c;
  int d;
  four(int _a, int _b, int _c, int _d) {
    a = _a;
    b = _b;
    c = _c;
    d = _d;
  }
  bool operator<(const four& f) const {
    return (a<f.a) ? true :
           (a>f.a) ? false:
           (b<f.b) ? true :   
           (b>f.b) ? false:
           (c<f.c) ? true :   
           (c>f.c) ? false:
           (d<f.d) ? true : 
           false;
  }
  bool operator==(const four& f) const {
    return ( a == f.a && b == f.b && c == f.c && d == f.d ); 
  }
};
 
struct fHash { 
  size_t operator()(const four& f) const {
    return ((f.a+1)*(f.b+1)*(f.c+1)*(f.d+1));
  }
};

vector<vector<int>> fourSum(vector<int>& nums, int target) {
  vector<vector<int>> ans; 
  if(nums.size()<4)  return ans;

  int n = nums.size();
  unordered_map<int, vector<pair<int,int> > > twosum; 
  twoSum.reserve(nums.size()*nums.size());

  for(int i=0;i<n-1;i++){
    for(int j=i+1;j<n;j++){
      pair<int, int> p = {i,j};
      twosum[nums[i]+nums[j]].emplace_back(p);
    }
  }

  unordered_set<four, fHash > s;
  for(auto v:twosum){
    if( !twosum.count(target-v.first) ) continue;
    for(auto p1:v.second) {
      vector<pair<int,int>> v2 = twosum[target-v.first];
      for(auto p2:v2){
        if(p1.first == p2.first || 
           p1.first == p2.second|| 
           p1.second== p2.first || 
           p1.second== p2.second) continue;
        vector<int> tmp { 
          nums[p1.first], 
          nums[p1.second],
          nums[p2.first],
          nums[p2.second]
        };
        sort(tmp.begin(),tmp.end());
        
        four f(tmp[0], tmp[1], tmp[2], tmp[3]);
        if(s.find(f)!=s.end()) continue;
        ans.emplace_back(tmp);
        s.emplace(f);
      }
    }
  }
  return ans;
}

int main(){
  vector<int> i1 {1,0,-1,0,-2,2};
  auto a1 = fourSum(i1, 0); 
  for(auto v:a1){
    for(auto vv:v){
      cout << vv << " ";
    }
    cout << endl;
  }
  cout << endl;
  vector<int> i2 {-4,-3,-2,-1,0,0,1,2,3,4};
  auto a2 = fourSum(i2, 0); 
  for(auto v:a2){
    for(auto vv:v){
      cout << vv << " ";
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}
