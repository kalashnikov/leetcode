#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

bool helper(vector<vector<char>>& board, const string& word, 
    int i, int j, int& idx) {
  if(i<0 || j<0 || i==board.size() || j==board[0].size() || 
      board[i][j] != word[idx] ) return false;
  if(idx==word.size()-1) return true;
  char c = board[i][j];
  board[i][j] = '0'; idx++;
  bool correct = helper(board, word, i+1, j  , idx) || 
                 helper(board, word, i  , j+1, idx) ||
                 helper(board, word, i-1, j  , idx) || 
                 helper(board, word, i  , j-1, idx)  ;
  board[i][j] = c;  idx--;
  return correct;
}

bool exist(vector<vector<char>>& board, string word) {
  if(board.size()==0) return false;
  int idx = 0, m = board.size(), n = board[0].size();
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      if(helper(board,word, i, j, idx)){
        return true;
      }
    }
  }
  return false;
}

int main(){
  vector<vector<char>> i1 {
    { 'A', 'B', 'C', 'E' },
    { 'S', 'F', 'C', 'S' },
    { 'A', 'D', 'E', 'E' } 
  };
  cout << exist(i1, "ABCCED") << " 1" << endl; 
  cout << exist(i1, "SEE") << " 1" << endl; 
  cout << exist(i1, "ABCB") << " 0" << endl; 
  
  vector<vector<char>> i2 {
    { 'C', 'A', 'A' },
    { 'A', 'A', 'A' },
    { 'B', 'C', 'D' } 
  };
  cout << exist(i2, "AAB") << " 1" << endl; 
  return 0;
}
