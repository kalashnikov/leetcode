#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

void helper(vector<vector<int>>& rooms, int i, int j, int cur){ 
  if ( i==-1 || j==-1 || i==rooms.size() || j==rooms[0].size() || rooms[i][j]<cur) return;
  rooms[i][j] = cur;
  helper(rooms, i+1, j, cur+1);
  helper(rooms, i, j+1, cur+1);
  helper(rooms, i-1, j, cur+1);
  helper(rooms, i, j-1, cur+1);
}

void wallsAndGates(vector<vector<int>>& rooms) {
  if(rooms.size()==0) return;
  int m = rooms.size(), n = rooms[0].size();
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      if(rooms[i][j]==0){
        helper(rooms, i, j, 0);
      }
    }
  }
}

int main(){

  int inf = 2147483647;
  vector<vector<int>> i1 { 
    { inf,  -1,   0, inf }, 
    { inf, inf, inf,  -1 }, 
    { inf,  -1, inf,  -1 }, 
    {   0,  -1, inf, inf } 
  };

  wallsAndGates(i1); 
  for(auto v:i1){
    for(auto vv:v){ 
      cout << vv << " ";
    }
    cout << endl; 
  } 
  cout << endl; 
  return 0;
}
