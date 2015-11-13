#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

vector<int> grayCode2(int n) {
  vector<int> ans, tmp; 
  ans.push_back(0);
  if ( n==0 ) return ans; 
  ans.push_back(1);

  int j = 1;
  while(j!=n){
    for(int i=ans.size()-1;i>=0;i--){
      ans.push_back( ans[i] | (1 << j));
    }
    j++;
  }
  return ans;
}

// https://leetcode.com/discuss/2978/what-solution-gray-code-problem-extra-space-used-recursion
vector<int> grayCode(int n) 
{         
  vector<int> result(1, 0);        
  for (int i = 0; i < n; i++) {
    int curCount = result.size();
    // push back all element in result in reverse order
    while (curCount) {
      curCount--;
      int curNum = result[curCount];
      curNum += (1<<i);
      result.push_back(curNum);
    } 
  }
  return result;
}

int main(){

  auto a1 = grayCode(2);
  for(auto v:a1) cout << v << " "; cout << endl;

  auto a2 = grayCode(3);
  for(auto v:a2) cout << v << " "; cout << endl;

  return 0;
}
