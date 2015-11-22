#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

// https://leetcode.com/discuss/13921/maybe-shortest-c-solution
vector<vector<int> > generate(int numRows) {
  vector<vector<int>> r(numRows);

  for (int i = 0; i < numRows; i++) {
    r[i].resize(i + 1);
    r[i][0] = r[i][i] = 1;

    for (int j = 1; j < i; j++)
      r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
  }

  return r;
}

vector<int> getRow(int rowIndex) {
  if(rowIndex<0)  return vector<int>();
  if(rowIndex==0) return vector<int>(1,1);
  if(rowIndex==1) return vector<int>(2,1);
  
  vector<int> ans;
  auto ritr = ans.rbegin();
  long long t = 1, num = rowIndex, den = 1;
  ans.push_back(1);
  while(num>den){
    t = t*num/den;
    ans.push_back(t);
    num--, den++;
  }
  ritr = ans.rbegin(); if(num!=den) ritr++;
  ans.insert(ans.end(),ritr,ans.rend());
  return ans;
}

// https://leetcode.com/discuss/18093/sharing-my-c-code-very-simple 
// Ex. getRow2(6)
// 1 0 0 0 0 0 0
// 1 1 0 0 0 0 0
// 1 2 1 0 0 0 0
// 1 3 3 1 0 0 0
// 1 4 6 4 1 0 0
// 1 5 10 10 5 1 0
// 1 6 15 20 15 6 1
// 1 6 15 20 15 6 1
vector<int> getRow2(int rowIndex) {
  vector<int> vi(rowIndex + 1);
  vi[0] = 1;
  for (int i = 0; i <= rowIndex ; ++i)
  {
    for (int j = i; j > 0; --j)
    {
      vi[j] = vi[j] + vi[j-1];
    }
    for(auto v:vi) cout << v << " "; cout << endl;
  }
  return vi;
}

// http://www.wikiwand.com/en/Pascal's_triangle
vector<vector<int>> generate_formula(int numRows) {
  vector<vector<int>> ans;
  if(numRows<1) return ans;
  ans.reserve(numRows);
  ans.push_back(vector<int>(1,1));
  if(numRows==1) return ans; 
  ans.push_back(vector<int>(2,1));
  if(numRows==2) return ans; 

  int t = 1, num = 1, den = 1;
  vector<int> tmp;
  auto ritr = tmp.rbegin();
  for(int i=2;i<numRows;i++){
    t = 1, num = i, den = 1;
    tmp.clear(); tmp.push_back(1);
    while(num>den){
      t = t*num/den;
      tmp.push_back(t);
      num--, den++;
    }
    ritr = tmp.rbegin(); if(num!=den) ritr++;
    tmp.insert(tmp.end(),ritr,tmp.rend());
    ans.push_back(tmp);
  } 
  return ans;
}

int main(){
  auto a1 = generate(1); 
  for(auto v:a1){
    for(auto vv:v){
      cout << vv << " ";
    } 
    cout << endl;
  } 
  cout << endl;
  
  auto a2 = generate(2); 
  for(auto v:a2){
    for(auto vv:v){
      cout << vv << " ";
    } 
    cout << endl;
  } 
  cout << endl;
  
  auto a3 = generate(6); 
  for(auto v:a3){
    for(auto vv:v){
      cout << vv << " ";
    } 
    cout << endl;
  } 
  cout << endl << endl;

  auto a4 = getRow2(6);
  for(auto v:a4) cout << v << " "; cout << endl;
  return 0;
}
