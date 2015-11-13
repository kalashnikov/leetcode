#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {
  if(board.size()!=9||board[0].size()!=9) return false;

  int bits = 0;

  // Row
  for(int i=0;i<9;i++) {
    bits = 0;
    for(int j=0;j<9;j++){
      if( board[i][j]=='.' ) continue;
      if( bits & ( 1 << (board[i][j]-'1') ) ) return false;
      bits |= 1 << (board[i][j]-'1');
    }
  }
 
  // Column 
  for(int j=0;j<9;j++){
    bits = 0;
    for(int i=0;i<9;i++) {
      if( board[i][j]=='.' ) continue;
      if( bits & ( 1 << (board[i][j]-'1') ) ) return false;
      bits |= 1 << (board[i][j]-'1');
    }
  }

  // Blocks 
  for(int i=0;i<9;i+=3) {
    for(int j=0;j<9;j+=3){
      bits = 0;
      for(int m=0;m<3;m++){ 
        for(int n=0;n<3;n++){
          if( board[i+m][j+n]=='.' ) continue;
          if( bits & ( 1 << (board[i+m][j+n]-'1') ) ) return false;
          bits |= 1 << (board[i+m][j+n]-'1');
        }
      }
    }
  }

  return true;
}

int main(){

  vector<vector<char>> i1 { 
    {'5','3','.','.','7','.','.','.','.'},
    {'6','.','.','1','9','5','.','.','.'},
    {'.','9','8','.','.','.','.','6','.'},
    {'8','.','.','.','6','.','.','.','3'},
    {'4','.','.','8','.','3','.','.','1'},
    {'7','.','.','.','2','.','.','.','6'},
    {'.','6','.','.','.','.','2','8','.'},
    {'.','.','.','4','1','9','.','.','5'},
    {'.','.','.','.','8','.','.','7','9'},
  };
  cout << isValidSudoku(i1) << endl;
  return 0;
}
