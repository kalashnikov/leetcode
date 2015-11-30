#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

int minimumTotal(vector<vector<int>>& triangle) {
  if (triangle.size()==0) return 0;
  int n = triangle.size();
  vector<int> ans(n,0);
  
  ans[0] = triangle[0][0];
  for(int i=1;i<n;i++) 
    ans[i] = triangle[i][0] = triangle[i][0] + triangle[i-1][0];  

  //for(auto v:ans) cout << v << " "; cout << endl;

  int minv = 0;
  for(int i=0;i<n;i++){ 
    for(int j=1;j<triangle[i].size();j++){
      minv = ( j==triangle[i].size()-1 ) ? triangle[i-1][j-1] : 
               min(triangle[i-1][j-1],triangle[i-1][j]);
      triangle[i][j] += minv;
      ans[i] = min(ans[i], triangle[i][j]);
    }
    //for(auto v:triangle[i]) cout << v << " "; cout << endl;
  }
  return ans.back();
}

int main(){
  vector<vector<int>> i1 { {2},{3,4},{6,5,7},{4,1,8,3} };
  cout << minimumTotal(i1) << " 11" << endl;
  return 0;
}
