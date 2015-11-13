#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

void backtrack(vector<vector<int>>& ans, vector<int> path, list<int> res){
  if (res.size()==0){
    ans.push_back(path);
    return;
  } else {
    for(int i=0;i<res.size();i++){
      vector<int> pp(path);
      int val = res.front(); 
      res.pop_front();
      pp.push_back(val);
      backtrack(ans, pp, res);
      res.push_back(val);
    }
  }
}

// Problem.46
vector<vector<int>> permute(vector<int>& nums) {
  vector<int> path;
  list<int> res(nums.begin(),nums.end());
  vector<vector<int>> ans;
  backtrack(ans, path, res);
  return ans;
}

void backtrackUnique(vector<vector<int>>& ans, vector<int> path, list<int> res){
  if (res.size()==0){
    ans.push_back(path);
    return;
  } else {
    int val;
    for(int i=0;i<res.size();i++){
      if ( i!=0 && res.front()==val ) {
        res.push_back(res.front());
        res.pop_front();
        continue; 
      }
      vector<int> pp(path);
      val = res.front(); 
      res.pop_front();
      pp.push_back(val);
      backtrack(ans, pp, res);
      res.push_back(val);
    }
  }
}

// Problem.47
vector<vector<int>> permuteUnique(vector<int>& nums) {
  vector<int> path;
  sort(nums.begin(),nums.end());
  list<int> res(nums.begin(),nums.end());
  vector<vector<int>> ans;
  backtrackUnique(ans, path, res);
  return ans;
}

int main(){

  vector<int> v1 {1,2,3};
  auto r1 = permute(v1);
  for(auto v:r1){
    for(auto vv:v){
      cout << vv << " ";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}
