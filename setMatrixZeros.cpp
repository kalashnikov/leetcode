#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

// O(1) 
// https://leetcode.com/discuss/15997/any-shortest-o-1-space-solution
void setZeroes(vector<vector<int> > &matrix) {
  int col0 = 1, rows = matrix.size(), cols = matrix[0].size();

  for (int i = 0; i < rows; i++) {
    if (matrix[i][0] == 0) col0 = 0;
    for (int j = 1; j < cols; j++)
      if (matrix[i][j] == 0)
        matrix[i][0] = matrix[0][j] = 0;
  }

  for (int i = rows - 1; i >= 0; i--) {
    for (int j = cols - 1; j >= 1; j--)
      if (matrix[i][0] == 0 || matrix[0][j] == 0)
        matrix[i][j] = 0;
    if (col0 == 0) matrix[i][0] = 0;
  }
}

// O(m+n) 
void setZeroes2(vector<vector<int>>& matrix) {
  if(matrix.size()==0) return ;

  int m = matrix.size(), n = matrix[0].size(); 
  vector<int> d(m+n,0);
  
  for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
      if(matrix[i][j]==0) 
        d[i] = d[m+j] = true;

  for(int i=0;i<m;i++)
    for(int j=0;j<n;j++)
      if(d[i] || d[m+j])
        matrix[i][j] = 0;
}

int main(){

  vector<vector<int>> i1 {
    { 0,0,0,5 }, 
    { 4,3,1,4 }, 
    { 0,1,1,4 }, 
    { 1,2,1,3 },
    { 0,0,1,1 } 
  };
  setZeroes(i1); 
  
  for(auto v:i1){ 
    for(auto vv:v){
      cout << vv << " ";
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}
