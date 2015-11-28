#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

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

// 20ms
int maximalRectangle(vector<vector<char>>& matrix) {
  if(matrix.size()==0) return 0;

  int ans = 0, m = matrix.size(), n = matrix[0].size();
  vector<int> height(n,0); // height

  for(int i=0;i<m;i++){  
    for(int j=0;j<n;j++){
      if(matrix[i][j]=='0') { 
        height[j] = 0;
        continue;
      }
      height[j]++;
      for(int cur = j-1, pre = height[j]; cur>=0; cur--){
        if ( height[cur] == 0 ) break;
        pre = min(pre,height[cur]);
        ans = max(ans, (j-cur+1)*pre);
      }
      ans = max(ans, height[j]);
    }
  }
  return ans;
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
  
  vector<vector<char>> i6 {
    {'1','0','1','0'},
    {'1','0','1','1'},
    {'1','0','1','1'},
    {'1','1','1','1'}};
  cout << maximalRectangle(i6) << " 6" << endl;
  
  vector<vector<char>> i7 {
    {'0', '1', '1', '0', '1'},
    {'1', '1', '0', '1', '0'},
    {'0', '1', '1', '1', '0'},
    {'1', '1', '1', '1', '0'},
    {'1', '1', '1', '1', '1'},
    {'0', '0', '0', '0', '0'}};
  cout << maximalRectangle(i7) << " 9" << endl; 
  return 0;
}
