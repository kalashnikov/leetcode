#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/discuss/42445/a-really-simple-and-readable-c-solution%EF%BC%8Conly-cost-12ms
// First, check the four border of the matrix. If there is a element is 'O', alter it and all its neighbor 'O' elements to '1'.
// Then , alter all the 'O' to 'X'
// At last, alter all the '1' to 'O'
// 
// For example:
//          X X X X           X X X X             X X X X
//          X X O X  ->       X X O X    ->       X X X X
//          X O X X           X 1 X X             X O X X
//          X O X X           X 1 X X             X O X X
void check(vector<vector<char> >&vec,const int i,const int j, const int row, const int col){
  if(vec[i][j]=='O'){
    vec[i][j]='1';
    if(i>1)     check(vec,i-1,j,row,col);
    if(j>1)     check(vec,i,j-1,row,col);
    if(i+1<row) check(vec,i+1,j,row,col);
    if(j+1<col) check(vec,i,j+1,row,col);
  }
}

void solve(vector<vector<char>>& board) {
  if(board.size()==0) return;
  int row=board.size();
  int col=board[0].size();

  for(int i=0;i<row;i++){
    check(board,i,0,row,col);
    if(col>1) check(board,i,col-1,row,col);
  }
  for(int j=1;j+1<col;j++){
    check(board,0,j,row,col);
    if(row>1) check(board,row-1,j,row,col);
  }
  for(int i=0;i<row;i++){
    for(int j=0;j<col;j++){
      if(board[i][j]=='O') { 
        board[i][j]='X';
      }
      if(board[i][j]=='1'){
        board[i][j]='O';
      }
    }
  }
}

int main(){
  vector<vector<char>> i1 { 
    {'X','X','X','X'}, 
    {'O','O','O','X'}, 
    {'X','X','O','X'}, 
    {'X','O','X','X'}
  };
  solve(i1);
  for(auto v:i1){
    for(auto vv:v){ 
      cout << vv << " ";
    }
    cout << endl; 
  } 
  cout << endl; 
  return 0;
}
