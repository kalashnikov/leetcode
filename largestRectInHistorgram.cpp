#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

struct cmp { 
  bool operator()(const pair<int, int>& a, const pair<int, int>& b) const {
    return a.first > b.first;
  }
};

// Hint from https://leetcode.com/discuss/61956/16ms-c-10-line-code-with-stack
int largestRectangleArea(vector<int>& height) {
  height.push_back(0);
  int sum, ans = 0, cur = 1;
  vector<int> s(height.size()+1, 0);
  s[0] = -1;

  for(int i=1;i<height.size();i++){
    while(cur && height[i] < height[s[cur]] ) {
      // Everytime if the height below previous node, 
      // we calculate the rectangle area
      sum = height[s[cur]] * (i-s[cur-1]-1);
      ans = max(ans,sum);
      cur--; // We delete it by decreasing the idx
    }
    s[++cur] = i; // Store it into the stack
  }
  return ans;
}

int largestRectangleArea1(vector<int>& height) {
  if(height.size()==0) return 0;
  int sum, minv, ans = height[0], last = 0;
  set<pair<int,int>, cmp> s;

  for(int i=0;i<height.size();i++){
    minv = i;
    while(s.size()!=0 && height[i] < s.begin()->first ) {
      // s.front to the one before
      sum = s.begin()->first * (i-s.begin()->second);
      ans = max(ans,sum);
      minv= min(minv,s.begin()->second);
      s.erase(s.begin()); 
    }
    if( height[i]==0 ) last = i;
    else s.insert(make_pair(height[i],minv));

    cout << ans << " | "; 
    for(auto v: s) cout << "(" << v.first << "," << v.second << ") "; cout << endl;
  }

  // Clean the lefts
  while(s.size()){
    // s.front to the one before
    sum = s.begin()->first * (height.size()-s.begin()->second); 
    ans = max(ans,sum);
    s.erase(s.begin());
  }
  return ans;
}

// https://leetcode.com/discuss/61956/16ms-c-10-line-code-with-stack
int largestRectangleArea2(vector<int>& height) {
  height.push_back(0);
  cout << "--------" << endl;
  cout << "## "; for(auto v:height) cout << v << " "; cout << endl;
  int len = height.size(),res = 0, cur=1;
  vector<int> s(len+1,0);
  s[0]=-1;
  for(int i=1;i<len;i++){
    while(cur && height[i]<height[s[cur]]) {
      cout << i << " " << cur << " | " << height[s[cur]] << " * " << (i-s[cur-1]-1) << endl;
      res = max(res, height[s[cur]] * (i-s[--cur]-1));
    }
    s[++cur]=i;
    for(auto v:s) cout << v << " "; cout << " | " << res << endl;
  }
  return res;
}

int main(){
  vector<int> i0 {2,1,2};
  cout << largestRectangleArea(i0) << endl;
  vector<int> i1 {2,1,5,6,2,3};
  cout << largestRectangleArea(i1) << endl;
  vector<int> i2 {4,2,0,3,2,5};
  cout << largestRectangleArea(i2) << endl;
  vector<int> i3 {3,6,5,7,4,8,1,0};
  cout << largestRectangleArea(i3) << endl;
  return 0;
}
