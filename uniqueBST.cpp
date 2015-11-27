#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

// https://leetcode.com/discuss/34569/very-simple-straight-based-math-catalan-number-times-space
int numTrees(int n) {
    long long ans=1,i;
    for(i=1;i<=n;i++)
        ans = ans*(i+n)/i;
    return ans/i;
}

// https://www.wikiwand.com/en/Catalan_number
int numTrees(int n) {
  static unordered_map<int, long> ans;
  ans[0] = 1; ans[1] = 1; ans[2] = 2;
  if(n<3||ans.count(n)) return ans[n]; 
  int i = 3; 
  while(i<=n){
    ans[i] = (4*i-2)*ans[i-1]/(i+1);
    i++;
  }
  return ans[n];
}

int main(){
  cout << numTrees(1) << "   1" << endl;
  cout << numTrees(2) << "   2" << endl;
  cout << numTrees(3) << "   5" << endl;
  cout << numTrees(4) << "  14" << endl;
  cout << numTrees(5) << "  42" << endl;
  cout << numTrees(6) << " 132" << endl;
  cout << numTrees(19) << " 1767263190" << endl;
  return 0;
}
