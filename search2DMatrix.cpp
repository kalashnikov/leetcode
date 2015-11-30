#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

// 20ms -> 12ms, Need quick return to speed up. 
bool searchMatrix1(vector<vector<int>>& matrix, int target) {
  if(matrix.size()==0) return false;
  if(target<matrix[0][0] || target>matrix.back().back()) return false;
  int i=0, j=0, m=matrix.size()-1, n=matrix[0].size()-1;
  while(i<m && target>=matrix[i+1][0]) i++;
  while(j<n && target>=matrix[i][j+1]) j++; 
  if(matrix[i][j]==target) return true;
  return false;
}

bool helper(vector<vector<int>>& matrix, int ilo, int ihi, int jlo, int jhi, const int& target) {
  if(ilo>ihi || jlo>jhi) return false;
  if(ilo>=matrix.size() || jlo>=matrix[0].size()) return false;
  int idx1 = ilo + (ihi-ilo)/2;
  int idx2 = jlo + (jhi-jlo)/2;
  //cout << ilo << " " << ihi  << "," << jlo << " " << jhi << " | " 
  //     << matrix[idx1][idx2] << endl;
  if(target == matrix[idx1][idx2]) return true;
  if(target < matrix[idx1][idx2]) {
    return helper(matrix, ilo, idx1-1, jlo, idx2-1, target) ||
           helper(matrix, idx1,  idx1, jlo, idx2-1, target) ||
           helper(matrix, ilo, idx1-1, idx2,  idx2, target);
  }
  return helper(matrix, idx1+1, ihi, idx2+1, jhi, target) || 
         helper(matrix, idx1+1, ihi,    jlo, jhi, target) ||
         helper(matrix, ilo,    ihi, idx2+1, jhi, target);
}

bool searchMatrix_recursive(vector<vector<int>>& matrix, int target) {
  if(matrix.size()==0) return false;
  if(matrix.size()==1&&matrix[0].size()==1) return target==matrix[0][0];
  if(target<matrix[0][0] || target>matrix.back().back()) return false;
  return helper(matrix, 0, matrix.size(), 0, matrix[0].size(), target); 
}

//////////////////////////////////////////////////////////////
// O(m+n)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
  int i = 0;
  int j = matrix[0].size() - 1;

  while(i < matrix.size() && j >= 0) {
    if(matrix[i][j] == target)
      return true;

    if(matrix[i][j] < target)
      i++;
    else
      j--;
  }

  return false;
}

// O(mlogn) 
bool searchMatrix(vector<vector<int>>& matrix, int target) {
  return searchMatrix(matrix, target, 0, matrix.size() - 1);
}

bool searchMatrix(vector<vector<int>>& matrix, int target, int top, int bottom) {
  if (top > bottom)
    return false;

  int mid = top + (bottom - top) / 2;
  if (matrix[mid].front() <= target && target <= matrix[mid].back())
    if (searchVector(matrix[mid], target)) return true;

  if (searchMatrix(matrix, target, top, mid - 1)) return true;
  if (searchMatrix(matrix, target, mid + 1, bottom)) return true;

  return false;
}

bool searchVector(vector<int>& v, int target) {
  int left = 0, right = v.size() - 1;

  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (v[mid] == target)
      return true;
    if (v[mid] < target)
      left = mid + 1;
    else
      right = mid - 1;
  }

  return false;
}
//////////////////////////////////////////////////////////////

int main(){

  vector<vector<int>> i1 { 
    { 1, 3, 5, 7},
    {10,11,16,20},
    {23,30,34,50}
  };
  cout << searchMatrix1(i1, 1) << " 1" << endl;

  vector<vector<int>> i2 {
    {1,   4,  7, 11, 15},
    {2,   5,  8, 12, 19},
    {3,   6,  9, 16, 22},
    {10, 13, 14, 17, 24},
    {18, 21, 23, 26, 30}
  }; 
  cout << searchMatrix(i2, 5) << " 1" << endl; 
  cout << searchMatrix(i2,20) << " 0" << endl;
  cout << searchMatrix(i2,15) << " 1" << endl;
  for(auto v: i2)
    for(auto vv:v) 
      if(searchMatrix(i2,vv)!=1){
        cout << vv << " is not founded." << endl;
      }

  vector<vector<int>> i3 {{1, 3, 4}};
  cout << searchMatrix(i3,5) << " 0" << endl;
  vector<vector<int>> i4 {{1,5}};
  cout << searchMatrix(i4,5) << " 1" << endl;
  return 0;
}
