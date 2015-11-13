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
      backtrack(ans, candidates, path, i, target-candidates[i]);
      path.pop_back();
    }
  }
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
  vector<int> path;
  vector<vector<int>> ans; 
  sort(candidates.begin(),candidates.end());
  backtrack(ans, candidates, path, 0, target);
  return ans;
}

int main(){

  vector<int> v1 {2,3,6,7};
  auto r1 = combinationSum(v1, 7);
  for(auto v:r1){
    for(auto vv:v){
      cout << vv << " ";
    }
    cout << endl;
  }
  cout << endl;
               
  vector<int> v2 {8,7,4,3};
  auto r2 = combinationSum(v2, 11);
  for(auto v:r2){
    for(auto vv:v){
      cout << vv << " ";
    }
    cout << endl;
  }
  cout << endl;
  
  return 0;
}
