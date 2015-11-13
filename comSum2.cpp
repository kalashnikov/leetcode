#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;


void backtrack(vector<vector<int>>& ans, vector<int>& candidates, vector<int>& path, int idx, int target){
  if ( target==0 ) {
    ans.push_back(path);
    return;
  } else { 
    for(int i=idx; i<candidates.size() && candidates[i]<=target; i++){
      path.push_back(candidates[i]);
      backtrack(ans, candidates, path, i+1, target-candidates[i]);
      path.pop_back();
    }
  }
}

vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
  vector<int> path;
  vector<vector<int>> ans; 
  sort(candidates.begin(),candidates.end());
  backtrack(ans, candidates, path, 0, target);

  sort(ans.begin(),ans.end());
  auto last = std::unique(ans.begin(), ans.end());
  ans.erase(last, ans.end());
  return ans;
}

int main(){

  vector<int> v1 {10,1,2,7,6,1,5};
  auto r1 = combinationSum2(v1, 8);
  for(auto v:r1){
    for(auto vv:v){
      cout << vv << " ";
    }
    cout << endl;
  }
  cout << endl;
               
  vector<int> v2 {8,7,4,3};
  auto r2 = combinationSum2(v2, 11);
  for(auto v:r2){
    for(auto vv:v){
      cout << vv << " ";
    }
    cout << endl;
  }
  cout << endl;
  
  return 0;
}
