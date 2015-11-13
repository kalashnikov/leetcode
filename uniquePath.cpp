#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

int uniquePaths(int m, int n) {
  if(m==0 || n==0) return 1;
  int array[m][n];
  memset(array, 0, sizeof(array));
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      if (i==0 || j==0) array[i][j] = 1;
      else array[i][j] = array[i-1][j] + array[i][j-1];
    }
  }
  return array[m-1][n-1];
}

int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
  if(obstacleGrid.size()==0 || obstacleGrid[0].size()==0) return 0;
  if(obstacleGrid[0][0]==1 ) return 0;
  if(obstacleGrid.size()==1 && obstacleGrid[0].size()==1) return 1;
 
  int m = obstacleGrid.size();
  int n = obstacleGrid[0].size();
  
  int array[m][n];
  memset(array, 0, sizeof(array));

  array[0][0] = 1;
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      if (obstacleGrid[i][j]==1) continue;
      if (i==0 && j==0 ) continue;
      if (i==0 && j!=0 ) array[i][j] = array[i][j-1];
      else if (i!=0 && j==0 ) array[i][j] = array[i-1][j];
      else array[i][j] = array[i-1][j] + array[i][j-1];
    }
  }
  return ( (m==0) ? array[0][n-1] : ((n==0) ? array[m-1][0] : array[m-1][n-1]));
}

int main(){
  //cout << uniquePaths(3,7) << endl;

  //vector<vector<int>> i1 { {0,0,0},{0,1,0},{0,0,0} };
  //cout << uniquePathsWithObstacles(i1) << endl;
  //
  //vector<vector<int>> i2 { {1,0} };
  //cout << uniquePathsWithObstacles(i2) << endl;
  //
  //vector<vector<int>> i3 { {0,0},{1,1},{0,0} };
  //cout << uniquePathsWithObstacles(i3) << endl;
  
  vector<vector<int>> i4 { {0,0} };
  cout << uniquePathsWithObstacles(i4) << endl;
  return 0;
}
