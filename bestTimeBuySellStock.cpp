#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

int maxProfit(vector<int>& prices) {
  int ans = 0; 
  for(int i=1;i<prices.size();i++){
    if ( prices[i] > prices[i-1] ) { 
      ans += prices[i]-prices[i-1];
    }
  }
  return ans;
}

int maxProfit1(vector<int>& prices) {
  if(prices.size()<2) return 0;
  int minv = prices[0] , ans = 0; 
  for(int i=1;i<prices.size();i++){
    ans  = max(ans,prices[i]-minv);
    minv = min(minv, prices[i]);
  }
  return ans;
}

int main(){
  vector<int> i1 { 1,2,5,3,9,7,4 };
  cout << maxProfit(i1) << " 8" << endl; 
  return 0;
}
