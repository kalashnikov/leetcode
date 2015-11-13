#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

int numIslands(vector<vector<char>>& grid) {

  int s1 = grid.size();
  if ( s1==0 ) return 0;
  int s2 = grid[0].size();
  if ( s2==0 ) return 0;

  // visisted table
  vector<vector<char>> note(grid);

  // Use for check
  const int row = s1;
  const int col = s2;
  int data[s1][s2];

  int count = 0;
  int islandIdx = 1;
 
  // Init queue
  list<pair<int, int>> q;
  for(int i=0;i<s1;i++){
    for(int j=0;j<s2;j++){ 
      if ( grid[i][j]=='1' ) 
        q.push_back(make_pair(i,j));
      data[i][j] = grid[i][j] - '0';
      //cout << data[i][j];
    }
  }

  // DFS
  int idx = 0, cnt = 0;
  pair<int, int> v;
  while(!q.empty()){
    v = q.front(); q.pop_front();

    if ( data[v.first][v.second]==0 || note[v.first][v.second]=='a' ) continue;
    cnt++;
    //cout << v.first << " " << v.second << "(" << data[v.first][v.second] << ")" << endl;

    // Get Island Idx
    if ( data[v.first][v.second]==1 ) {
      idx = ++islandIdx; count++;
      data[v.first][v.second] = idx; 
    } else { 
      idx = data[v.first][v.second]; 
    } 

    // Push adj entry
    if ( v.first+1 < s1 ) { 
      if ( idx>1 && data[v.first+1][v.second]==1 ) data[v.first+1][v.second] = idx;
      q.push_front(make_pair(v.first+1,v.second));
    }
    
    if ( v.second+1 < s2 ) {
      if ( idx>1 && data[v.first][v.second+1]==1 ) data[v.first][v.second+1] = idx;
      q.push_front(make_pair(v.first,v.second+1));
    }
    
    if ( v.first > 0 ) { 
      if ( idx>1 && data[v.first-1][v.second]==1 ) data[v.first-1][v.second] = idx;
      q.push_front(make_pair(v.first-1,v.second));
    }
    
    if ( v.second > 0 ) {
      if ( idx>1 && data[v.first][v.second-1]==1 ) data[v.first][v.second-1] = idx;
      q.push_front(make_pair(v.first,v.second-1));
    }

    note[v.first][v.second] = 'a'; 
  }

  return islandIdx-1;
  //return (int)(islandIdx-'1');
  //return count;
}


/*
 * Good Solution
 *
int numIslands(vector<vector<char>>& grid) {
  int num = 0;
  for(int i = 0; i<grid.size(); i++)
    for(int j = 0; j<grid[0].size(); j++)
      if(grid[i][j] == '1') { 
        DFS(grid, i, j);
        num++;
      }
  return num;
}

void DFS(vector<vector<char>>& grid, int i, int j){
  if(i == grid.size() || i < 0 || j == grid[0].size() || j < 0 || grid[i][j] != '1') return;
  grid[i][j] = '0' ;
  DFS(grid, i+1, j);
  DFS(grid, i, j+1);
  DFS(grid, i-1, j);
  DFS(grid, i, j-1);
}
*/

int main(){

  vector<vector<char>> vec1 { 
      {'1','1','1','1','0'}, 
      {'1','1','0','1','0'},
      {'1','1','0','0','0'},
      {'0','0','0','0','0'}};

  vector<vector<char>> vec2 { 
      {'1','1','0','0','0'}, 
      {'1','1','0','0','0'},
      {'0','0','1','0','0'},
      {'0','0','0','1','1'}};

  vector<vector<char>> vec3 { 
    {'1','0','0','1','1','1','0','1','1','0','0','0','0','0','0','0','0','0','0','0'},
    {'1','0','0','1','1','0','0','1','0','0','0','1','0','1','0','1','0','0','1','0'},
    {'0','0','0','1','1','1','1','0','1','0','1','1','0','0','0','0','1','0','1','0'},
    {'0','0','0','1','1','0','0','1','0','0','0','1','1','1','0','0','1','0','0','1'},
    {'0','0','0','0','0','0','0','1','1','1','0','0','0','0','0','0','0','0','0','0'},
    {'1','0','0','0','0','1','0','1','0','1','1','0','0','0','0','0','0','1','0','1'},
    {'0','0','0','1','0','0','0','1','0','1','0','1','0','1','0','1','0','1','0','1'},
    {'0','0','0','1','0','1','0','0','1','1','0','1','0','1','1','0','1','1','1','0'},
    {'0','0','0','0','1','0','0','1','1','0','0','0','0','1','0','0','0','1','0','1'},
    {'0','0','1','0','0','1','0','0','0','0','0','1','0','0','1','0','0','0','1','0'},
    {'1','0','0','1','0','0','0','0','0','0','0','1','0','0','1','0','1','0','1','0'},
    {'0','1','0','0','0','1','0','1','0','1','1','0','1','1','1','0','1','1','0','0'},
    {'1','1','0','1','0','0','0','0','1','0','0','0','0','0','0','1','0','0','0','1'},
    {'0','1','0','0','1','1','1','0','0','0','1','1','1','1','1','0','1','0','0','0'},
    {'0','0','1','1','1','0','0','0','1','1','0','0','0','1','0','1','0','0','0','0'},
    {'1','0','0','1','0','1','0','0','0','0','1','0','0','0','1','0','1','0','1','1'},
    {'1','0','1','0','0','0','0','0','0','1','0','0','0','1','0','1','0','0','0','0'},
    {'0','1','1','0','0','0','1','1','1','0','1','0','1','0','1','1','1','1','0','0'},
    {'0','1','0','0','0','0','1','1','0','0','1','0','1','0','0','1','0','0','1','1'},
    {'0','0','0','0','0','0','1','1','1','1','0','1','0','0','0','1','1','0','0','0'}};

  vector<vector<char>> vec4 {{'1','0','1','1','0','1','1'}};

  vector<vector<char>> vec0 {};

  vector<vector<char>> vec5 { 
    {'1','1','1'},{'0','1','0'},{'1','1','1'}};

  vector<vector<char>> vec6 { 
      {'1','0','1','1','1'}, 
      {'1','0','1','0','1'},
      {'1','1','1','0','1'}};

  cout << numIslands(vec0) << endl;
  cout << numIslands(vec1) << endl;
  cout << numIslands(vec2) << endl;
  cout << numIslands(vec3) << endl;
  cout << numIslands(vec4) << endl;
  cout << numIslands(vec5) << endl;
  cout << numIslands(vec6) << endl;

  return 0;
}
