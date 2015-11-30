#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
  vector<vector<int>> ans(A.size(),vector<int>(B[0].size(),0));
  if(A.size()==0||B.size()==0||A[0].size()!=B.size()) return ans;

  int n = B.size();
  
  vector<bool> exist(n,false); // PreCheck
  for(int i=0;i<A.size();i++){
    for(int j=0;j<B.size();j++){
      if(A[i][j]!=0) {
        exist[i] = true;
        break;
      }
    }
  }

  for(int j=0;j<B[0].size();j++){
    for(int i=0;i<B.size();i++){
      if(B[i][j]!=0) {
        exist[j] = true;
        break;
      }
    }
  }

  for(int i=0;i<A.size();i++){
    if(!exist[i]) continue;
    for(int j=0;j<B.size();j++){
      for(int k=0;k<n;k++){
        ans[i][j] += A[i][k]*B[k][j]; 
      }
    }
  }
  return ans;
}

int main(){

  vector<vector<int>> a1 { {1,0,0}, {-1,0,3} };
  vector<vector<int>> b1 { {7,0,0}, { 0,0,0}, { 0,0,1} };
  auto v1 = multiply(a1, b1);
  for(auto vv: v1) {
    for(auto vvv: vv)
      cout << vvv << " "; 
    cout << endl;
  }
  cout << endl;
  return 0;
}
