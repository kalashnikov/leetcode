#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

// 8ms
void helper(vector<vector<string>>& result, vector<int>& cur, const int& k){
  if(cur.size()==k){
    //for(auto v:cur) cout << v << " "; cout << endl;
    vector<string> sol(k,string(k,'.'));
    for(int i=0;i<cur.size();i++){
      sol[i][cur[i]] = 'Q';
    }
    result.push_back(sol);
  } else {
    // Try to place queen in this row 
    bool ok = true;
    for(int i=0;i<k;i++){ // column # 
      // Check conflict 
      ok = true;
      for(int j=0;j<cur.size();j++){
        if(i==cur[j] || (cur.size()-j)==abs(cur[j]-i)){
          ok = false;
          break;
        }
      }
      if ( ok ) {
        cur.push_back(i); 
        helper(result,cur,k);
        cur.pop_back(); 
      }
    }
  }
}

vector<vector<string>> solveNQueens(int n) {
  vector<int> cur; 
  vector<vector<string>> ans;
  helper(ans,cur,n);
  return ans;
}

void helper(int& result, vector<int>& cur, const int& k){
  if(cur.size()==k){
    result++;
  } else {
    // Try to place queen in this row 
    bool ok = true;
    for(int i=0;i<k;i++){ // column # 
      // Check conflict 
      ok = true;
      for(int j=0;j<cur.size();j++){
        if(i==cur[j] || (cur.size()-j)==abs(cur[j]-i)){
          ok = false;
          break;
        }
      }
      if ( ok ) {
        cur.push_back(i); 
        helper(result,cur,k);
        cur.pop_back(); 
      }
    }
  }
}

int totalNQueens(int n) {
  // Solve
  int ans = 0;
  vector<int> cur;
  helper(ans, cur, n);
  return ans;
}

int main(){
  auto a1 = solveNQueens(4);
  for(auto v:a1) { 
    for(auto vv:v)
      cout << vv << " ";
    cout << endl;
  }
  cout << endl;
  cout << totalNQueens(4) << endl;
  return 0;
}
