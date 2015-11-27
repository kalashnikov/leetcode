#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

int maximalRectangle(vector<vector<char>>& matrix) {
  if(matrix.size()==0) return 0;
  if(matrix.size()==1&&matrix[0].size()==1&&matrix[0][0]=='1') return 1;

  char tmp;
  int ans = 0, t, area;
  vector<vector<char>> dup(matrix); 
  for(int i=0;i<dup.size();i++){
    for(int j=1;j<dup[i].size();j++){
      if(dup[i][j]=='1'){
        t = dup[i][j-1] - '0' + 1;
        if ( t > dup[i][j] - '0' ) {
          dup[i][j] = char('0' + t);
          ans = max(ans,t);
        }
      }
    }
  }
  vector<vector<char>> dup2(matrix); 
  for(int j=0;j<dup2[0].size();j++){
    for(int i=1;i<dup2.size();i++){
      if(dup2[i][j]=='1'){
        t = dup2[i-1][j] - '0' + 1;
        if ( t > dup2[i][j] - '0' ) {
          dup2[i][j] = char('0' + t);
          ans = max(ans,t);
        }
      }
    }
  }
  
  vector<vector<int>> ar(matrix.size(), vector<int>(matrix[0].size(),0)); 

  for(int i=0;i<matrix.size();i++){
    for(int j=0;j<matrix[i].size();j++){
      if(ans==0&&matrix[i][j]=='1'&&(i==0||j==0)){ ans = ar[i][j] = 1; }
      if(i!=0&&j!=0&&matrix[i][j]=='1'){
        t = min(min(matrix[i-1][j]-'0',matrix[i][j-1]-'0'), matrix[i-1][j-1]-'0') + 1;
        matrix[i][j] = char('0' + t);
        ar[i][j]=t;
      }
    }
  }

  for(int i=1;i<ar.size();i++){
    for(int j=1;j<ar[i].size();j++){
      if(ar[i][j]>0){
        ar[i][j] *= ar[i][j];
        if(matrix[i][j]==matrix[i][j-1]) { 
          //ar[i][j] += matrix[i][j-1]-'0';
          ar[i][j] = max(ar[i][j] + matrix[i][j-1]-'0',ar[i][j-1]+matrix[i][j]-'0');
        }
        if(matrix[i][j]==matrix[i-1][j]) {
          //ar[i][j] += matrix[i-1][j]-'0';
          ar[i][j] = max(ar[i][j] + matrix[i-1][j]-'0',ar[i-1][j]+matrix[i][j]-'0');
        }
        //cout << ar[i][j] << " ";
        ans = max(ans, ar[i][j]);
      }
    }
    //cout << endl;
  }
  return ans;
}

// 12ms
int maximalSquare(vector<vector<char>>& matrix) {
  if(matrix.size()==0) return 0;
  if(matrix.size()==1&&matrix[0][0]=='1') return 1;

  char tmp;
  int ans = 0, t;
  for(int i=0;i<matrix.size();i++){
    for(int j=0;j<matrix[i].size();j++){
      if(ans==0&&matrix[i][j]=='1'&&(i==0||j==0)){ ans = 1; }
      if(i!=0&&j!=0&&matrix[i][j]=='1'){
        t = min(min(matrix[i-1][j]-'0',matrix[i][j-1]-'0'), matrix[i-1][j-1]-'0') + 1;
        ans = max(ans,t);
        matrix[i][j] = char('0' + t);
      }
    }
  }
  return ans*ans;
}

int main(){
  vector<vector<char>> i1 {
    {'1', '1', '1', '1', '1'},
    {'1', '0', '1', '1', '1'},
    {'1', '1', '1', '1', '0'},
    {'1', '0', '0', '1', '0'}};
  //cout << maximalSquare(i1) << endl;
  cout << maximalRectangle(i1) << " 6" << endl; 

  vector<vector<char>> i2 {{'1','1'}};
  //cout << maximalSquare(i2) << endl;
  cout << maximalRectangle(i2) << " 2" << endl;

  vector<vector<char>> i3 {
    {'1','1','1','1','1','1','1','1'},
    {'1','1','1','1','1','1','1','0'},
    {'1','1','1','1','1','1','1','0'},
    {'1','1','1','1','1','0','0','0'},
    {'0','1','1','1','1','0','0','0'}};
  cout << maximalRectangle(i3) << " 21" << endl;
  
  vector<vector<char>> i4 {
    {'1','1','0','1'},
    {'1','1','0','1'},
    {'1','1','1','1'}};
  cout << maximalRectangle(i4) << " 6" << endl;

  vector<vector<char>> i5 { 
    {'0','0','1','0'},
    {'1','1','1','1'},
    {'1','1','1','1'},
    {'1','1','1','0'},
    {'1','1','0','0'},
    {'1','1','1','1'},
    {'1','1','1','0'}};
  cout << maximalRectangle(i5) << " 12" << endl;
  return 0;
}
