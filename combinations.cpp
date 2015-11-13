#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

void backtrack(vector<vector<int>>& ans, vector<int>& path, int start, int num, int limit){
  if ( num==0 ) {
    ans.push_back(path);
    return;
  } else { 
    for(int i=start; i<limit+1; i++){
      path.push_back(i);
      backtrack(ans, path, i+1, num-1, limit);
      path.pop_back();
    }
  }
}

vector<vector<int>> combine(int n, int k) {
  vector<int> path;
  vector<vector<int>> ans; 
  backtrack(ans, path, 1, k, n);
  return ans;
}

int main(){

  auto r1 = combine(4, 2);
  for(auto v:r1){
    for(auto vv:v){
      cout << vv << " ";
    }
    cout << endl;
  }
  cout << endl;
  
  return 0;
}
