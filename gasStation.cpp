#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

// 8ms, DP
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
  if(gas.size()==0||cost.size()==0) return -1;

  int n = gas.size();

  int i = 0, j, cur;
  while(i<n){ 
    cur = gas[i]-cost[i]; 
    if(cur>=0){
      for(j=(i+1)%n;j!=i;j=(j+1)%n){
        cur += gas[j]-cost[j];
        if(cur<0) break;
      }
      if(cur>=0 && i==j) return i;
      else if ( j < n && j+1!=i ) i = j + 1;
      else return -1;
    } else {
      i++;
    }
  }
  return -1;
}

int main(){
  vector<int> i1 { 5,2,1,3,6 };
  vector<int> i2 { 3,4,2,5,1 };
  cout << canCompleteCircuit(i1, i2) << " 4" << endl;
  
  vector<int> i12{ 2,4 };
  vector<int> i22{ 3,4 };
  cout << canCompleteCircuit(i12, i22) << " -1" << endl;
  
  vector<int> i13{ 2,3,1 };
  vector<int> i23{ 3,1,2 };
  cout << canCompleteCircuit(i13, i23) << " 1" << endl;
  return 0;
}
