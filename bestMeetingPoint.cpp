#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

int minTotalDistance(vector<int>& grid) {
  int i = 0, j = grid.size() - 1, sum = 0;

  // For each distance pair, 
  // their sum distance to best meeting point should be their distance in between. 
  while(i < j) {
    sum += grid[j--] - grid[i++];
  }
  return sum;
}

int minTotalDistance(vector<vector<int>>& grid) {
  int m = grid.size(), n = grid[0].size();

  vector<int> I, J;
  // Push back each x-coordinate in increasing order
  for(int i = 0; i < m; i++) {
    for(int j = 0; j < n; j++) {
      if(grid[i][j] == 1) {
        I.push_back(i);
      }
    }
  }
  // Push back each y-coordinate in increasing order
  for(int j = 0; j < n; j++) {
    for(int i = 0; i < m; i ++) {
      if(grid[i][j] == 1) {  
        J.push_back(j);
      }
    }
  }
  return minTotalDistance(I) + minTotalDistance(J);
}

int minTotalDistance2(vector<vector<int>>& grid) {
  if(grid.size()==0) return 0;
  bool debug = true;
  int ans = INT_MAX, cnt = 0;
  double x = 0, y = 0;
  vector<pair<int,int>> points;
  for(int i=0;i<grid.size();i++){
    for(int j=0;j<grid[i].size();j++){
      if ( debug ) cout << grid[i][j] << " ";
      if (grid[i][j]==1){
        x += i;
        y += j;
        points.push_back({i,j});
        cnt++;
      }
    }
    if ( debug ) cout << endl;
  }
  if ( debug ) cout << endl;
  x = round(x / (double)cnt); 
  y = round(y / (double)cnt); 
  if ( debug ) cout << "MP: " << x << " " << y << endl;

  int ts = 0, mul = 2;
  for(int i=0;i<2;i++){ 
    for(int j=0;j<2;j++){
      ts = 0, mul = 1;
      for(int k=0;k<points.size();k++){
        ts += abs(points[k].first-(x+i)) + abs(points[k].second-(y+j));
      }
      if ( debug && ts < ans ) cout << "MP: " << (x+i) << " " << (y+j) << endl;
      while ( ts < ans ) {
        ans = min(ts, ans); 
        ts = 0, mul++;  
        for(int k=0;k<points.size();k++){
          ts += abs(points[k].first-(x+mul*i)) + abs(points[k].second-(y+mul*j));
        }
        if ( debug && ts < ans ) cout << "MP: " << (x+i) << " " << (y+j) << endl;
      }
    }
  }
  return ans;
}

int main(){

  vector<vector<int>> i1{{1,0,0,0,1},{0,0,0,0,0},{0,0,1,0,0}};
  cout << minTotalDistance(i1) << endl;
  
  vector<vector<int>> i2{{0,0,0,0,0,0,0,0,0},{0,0,0,0,1,0,0,1,0},{1,1,0,0,0,0,1,0,0},{0,0,0,1,1,1,0,0,0}};
  cout << minTotalDistance(i2) << endl;

//  vector<vector<int>> i3{{1,1,0,0,0,1},{0,0,1,0,0,0},{0,1,1,0,0,0},{0,0,1,0,1,0},{0,0,0,0,0,0},{0,0,0,0,0,0},{0,0,0,0,0,1},{0,1,0,0,0,0},{0,1,0,0,0,0},{0,0,0,0,1,0},{0,0,0,0,0,0},{1,1,1,1,1,1},{0,1,0,0,1,1},{0,0,0,1,1,0},{0,1,0,0,0,0},{1,1,1,1,0,1},{0,0,0,0,0,0}};
//  cout << minTotalDistance(i3) << endl;
//
//
//  vector<vector<int>> i4{{0,0,1},{1,0,1},{1,1,0},{0,1,1},{1,0,0},{0,0,0},{0,0,0},{1,0,0},{0,0,0},{0,1,1},{0,0,0},{0,0,0},{1,1,0},{0,1,0},{0,0,0},{0,1,0},{0,0,0},{0,1,0},{1,0,0},{0,0,0},{0,0,1},{0,1,1},{1,0,1},{0,0,0},{1,1,0},{1,0,0},{0,1,0},{1,0,0},{0,1,0},{0,0,1},{1,0,0},{0,0,1},{1,0,1},{1,0,0},{1,0,0},{1,1,0},{0,0,0},{1,0,1},{0,1,0},{1,1,0},{0,0,0}};
//  cout << minTotalDistance(i4) << endl;
  return 0;
}
