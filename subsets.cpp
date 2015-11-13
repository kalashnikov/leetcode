#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <list>

using namespace std;

void helper(vector<vector<int>>& ans, list<int> l, vector<int> cur){
  if (l.size()==0) { ans.push_back(cur); return; } 
  int val = l.front();
  l.pop_front();
  helper(ans, l, cur); // add front() 
  cur.push_back(val);
  helper(ans, l, cur); // No add front()
  return ;
}

vector<vector<int>> subsets(vector<int>& nums) {
  vector<int> s;
  vector<vector<int>> ans;
  if ( nums.size()==0 ) {
    ans.push_back(s);
    return ans;
  }
  sort(nums.begin(),nums.end());
  list<int> l(nums.begin(),nums.end());
  helper(ans,l,s);
  return ans;
}

void helperDup(set<vector<int>>& ans, list<int> l, vector<int> cur){
  if (l.size()==0) { ans.insert(cur); return; }
  int val = l.front();
  l.pop_front();
  helperDup(ans, l, cur); // add front()
  cur.push_back(val);
  helperDup(ans, l, cur); // No add front()
  return ;
}

vector<vector<int>> subsetsWithDup2(vector<int>& nums) {
  vector<int> s;
  set<vector<int>> _ans;
  if ( nums.size()==0 ) {
    vector<vector<int>> ans;
    ans.push_back(s);
    return ans;
  }
  sort(nums.begin(),nums.end());
  list<int> l(nums.begin(),nums.end());
  helperDup(_ans,l,s);
  vector<vector<int>> ans(_ans.begin(),_ans.end());
  return ans;
}

// https://leetcode.com/discuss/11905/simple-iterative-solution 
vector<vector<int> > subsetsWithDup(vector<int> &S) {
  sort(S.begin(), S.end());
  vector<vector<int>> ret = {{}};
  int size = 0, startIndex = 0;
  for (int i = 0; i < S.size(); i++) {
    startIndex = i >= 1 && S[i] == S[i - 1] ? size : 0;
    size = ret.size();
    cout << "#### " << startIndex << " " << size << " | " << S[i] << endl;
    for (int j = startIndex; j < size; j++) {
      vector<int> temp = ret[j];
      temp.push_back(S[i]);
      ret.push_back(temp);
      for(auto v:temp) cout << v << " "; cout << endl;
    }
    cout << "#### " << size << endl;
  }
  return ret;
}

int main(){

  vector<int> v1 {1,1,2,2};
  auto a1 = subsetsWithDup(v1);
  for(auto v:a1) {
    for(auto vv:v) 
      cout << vv << " ";
    cout << endl;
  }
  cout << endl;

  return 0;
}
