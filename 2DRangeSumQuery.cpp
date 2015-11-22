#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

class NumMatrix {
  vector<vector<int>>* cache;
  public:
    NumMatrix(vector<vector<int>> &matrix) {
      if ( matrix.size()==0 ) return;
      int n = matrix.size(), m = matrix[0].size();
      cache = new vector<vector<int>>(n,vector<int>(m,0));
      // First row
      int sum = 0;
      for(int j=0;j<m;j++){ 
        sum += matrix[0][j];
        (*cache)[0][j] = sum;
      }
      for(int i=1;i<n;i++){
        sum = 0;
        for(int j=0;j<m;j++){
          sum += matrix[i][j];
          (*cache)[i][j] = sum + (*cache)[i-1][j];
        }
      }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
      if ( row1 > row2 || col1 > col2 || col1 < 0 || col2 < 0 ||
           row1 < 0 || row2 < 0 ) return 0;
      int minus1 = (col1==0 ) ? 0 : (*cache)[row2][col1-1];
      int minus2 = (row1==0 ) ? 0 : (*cache)[row1-1][col2];
      int add    = (row1==0 || col1==0 ) ? 0 : (*cache)[row1-1][col1-1];
      return (*cache)[row2][col2] - minus1 - minus2 + add;
    }
};

int main(){
  vector<vector<int>> matrix{
  {3, 0, 1, 4, 2},
  {5, 6, 3, 2, 1},
  {1, 2, 0, 1, 5},
  {4, 1, 0, 1, 7},
  {1, 0, 3, 0, 5}};
  NumMatrix numMatrix(matrix);
  
  for(int i=0;i<matrix.size();i++){
    for(int j=0;j<matrix[0].size();j++){
      cout << matrix[i][j] << "(" << numMatrix.sumRegion(i,j,i,j) << ") ";
    }
    cout << endl;
  }
  cout << endl;

  cout << numMatrix.sumRegion(2, 1, 4, 3) << endl; //-> 8
  cout << numMatrix.sumRegion(1, 1, 2, 2) << endl; //-> 11
  cout << numMatrix.sumRegion(1, 2, 2, 4) << endl; //-> 12
  return 0;
}
