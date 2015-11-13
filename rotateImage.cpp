#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

void rotate(vector<vector<int>>& matrix) {
  if ( matrix.size()==0 || matrix[0].size()!=matrix.size() ) return;

  int n = matrix.size(); 
  int start = 0, end = n-1;
  while(start<end){
    for(int j=end, i=start; j>start; j--,i++){ 
      swap(matrix[j][end],   matrix[start][j]); 
      swap(matrix[start][j], matrix[i][start]); 
      swap(matrix[i][start], matrix[end][i]); 
      //printf("(%d, %d) (%d, %d)\n", j,   end, start, j);
      //printf("(%d, %d) (%d, %d)\n", start, j, end-j, start);
      //printf("(%d, %d) (%d, %d)\n\n", end-j, start,   end, end-j);
    }
    //for(int i=0;i<matrix.size();i++){
    //  for(int j=0;j<matrix[i].size();j++){
    //    cout << matrix[i][j] << " ";
    //  }
    //  cout << endl;
    //}
    //cout << endl;
    start++, end--;
  }

  return;
}

int main(){

  vector<vector<int>> i1 { {1,2,3,4}, {5,6,7,8}, {9,10,11,12},{13,14,15,16} };
  rotate(i1);
  for(int i=0;i<i1.size();i++){
    for(int j=0;j<i1[i].size();j++){
      cout << i1[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}
