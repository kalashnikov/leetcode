#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

int minPathSum(vector<vector<int>>& grid) {
  if(grid.size()==0) return 0;
  if(grid.size()==1&&grid[0].size()==1) return grid[0][0];
  
  int m = grid.size(), n = grid[0].size();
  for(int i=1;i<n;i++)  grid[0][i] += grid[0][i-1];
  for(int i=1;i<m;i++)  grid[i][0] += grid[i-1][0];

  for(int i=1;i<m;i++){
    for(int j=1;j<n;j++){
      grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
    }
  }
  return grid.back().back();
}

int main(){

  vector<vector<int>> i1 {
    { 1,2,3 },
    { 4,9,1 },
    { 8,7,6 },
    { 8,2,1 }};
  cout << minPathSum(i1) << endl;

  return 0;
}
