#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

// Use original container 
// https://leetcode.com/discuss/61568/o-n-time-and-o-1-space-c-solution
int minCost(vector<vector<int>>& costs) {
  int n = costs.size();
  for (int i = 1; i < n; i++) {
    costs[i][0] += std::min(costs[i - 1][1], costs[i - 1][2]);
    costs[i][1] += std::min(costs[i - 1][0], costs[i - 1][2]);
    costs[i][2] += std::min(costs[i - 1][0], costs[i - 1][1]);
  }
  return (n == 0) ? 0 : (std::min(costs[n - 1][0], std::min(costs[n - 1][1], costs[n - 1][2])));
}

// 12 ms
int minCost1(vector<vector<int>>& costs) {
  if(costs.size()<1) return 0;

  vector<vector<int>> ans(costs.size(), vector<int>(3,0));
  for(int i=0;i<3;i++) ans[0][i] = costs[0][i];

  for(int i=1;i<costs.size();i++){

    if ( ans[i-1][1] < ans[i-1][2] ) { 
      ans[i][0] = ans[i-1][1] + costs[i][0]; 
    } else {
      ans[i][0] = ans[i-1][2] + costs[i][0]; 
    }

    if ( ans[i-1][0] < ans[i-1][2] ) { 
      ans[i][1] = ans[i-1][0] + costs[i][1]; 
    } else {
      ans[i][1] = ans[i-1][2] + costs[i][1]; 
    }
    
    if ( ans[i-1][0] < ans[i-1][1] ) { 
      ans[i][2] = ans[i-1][0] + costs[i][2]; 
    } else {
      ans[i][2] = ans[i-1][1] + costs[i][2]; 
    }
  }

  //for(auto v:ans[0]) cout << v << " "; cout << endl;
  //for(auto v:ans[1]) cout << v << " "; cout << endl;
  //for(auto v:ans[2]) cout << v << " "; cout << endl;

  return min(min(ans[costs.size()-1][0],ans[costs.size()-1][1]),ans[costs.size()-1][2]);
}

// 32ms 
int minCostII(vector<vector<int>>& costs) {
  if ( costs.size()==0 ) return 0;
  int n = costs.size(), m = costs[0].size(), minv;
  for (int i = 1; i < n; i++) {
    for(int j = 0; j < m; j++) {
      minv = INT_MAX;
      for(int k = 0; k < m ; k++){
        if ( k==j ) continue;
        minv = min(costs[i-1][k], minv);
      }
      costs[i][j] += minv;
    }
  }
  return *min_element(costs[n-1].begin(),costs[n-1].end());
}

// 24ms, less comparison
// https://leetcode.com/discuss/52982/c-dp-time-o-nk-space-o-k
int minCostII(vector<vector<int>>& costs) {
  if (costs.empty()) return 0;
  int n = costs.size(), k = costs[0].size(), m1 = 0, m2 = 0;
  vector<int> dp(k, 0);
  for (int i = 0; i < n; i++) {
    int t1 = m1, t2 = m2;
    m1 = m2 = INT_MAX;
    for (int j = 0; j < k; j++) {
      dp[j] = (dp[j] != t1 ? t1 : t2) + costs[i][j];
      if (m1 <= dp[j]) m2 = min(m2, dp[j]);
      else m2 = m1, m1 = dp[j];
    }
  }
  return m1;
}

// Another version by benlong
struct Position {
    int index;
    int value;
    Position (int _i, int _v) : index (_i), value (_v) {}
};

//(nk) time O(1) auxiliary space;
int minCostII(vector<vector<int>>& costs) {
    int n = costs.size();
    if (n == 0) {
        return 0;
    }

    //I think it's better to return 0 when painting 
    //more than 1 houses with a single color;
    int k = costs[0].size();
    if (k == 1) {
        return n == 1 ? costs[0][0] : 0;
    }

    Position min1 (-1, 0), min2 (-1, 0);
    for (int i = 0; i < n; i++) {
        Position tmp1 = min1, tmp2 = min2;
        min1.value = INT_MAX;
        min2.value = INT_MAX;
        for (int j = 0; j < k; j++) {
            int cost = (j != tmp1.index ? tmp1.value : tmp2.value) + costs[i][j];

            //update the min1 and min2 of the current row;
            if (cost < min1.value) {
                min2 = min1;
                min1 = Position (j, cost);
            } else if (cost < min2.value) {
                min2 = Position (j, cost);
            }
        }
    }

    return min1.value;
}

int main(){

  vector<vector<int>> i1 { {0,1,2}, {2,1,0}, {3,2,1} };
  cout << minCostII(i1) << " 2" << endl;

  vector<vector<int>> i2 {{5,8,6},{19,14,13},{7,5,12},{14,15,17},{3,20,10}};
  cout << minCostII(i2) << " 43" << endl;
  return 0;
}
