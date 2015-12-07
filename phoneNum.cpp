#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

vector<string> letterCombinations(string digits) {
  if(digits.length()==0) return vector<string>();

  const vector<string> m { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" }; 

  int idx = 0;
  vector<string> ans {""} , tmp;
  for(int i=0;i<digits.length();i++){
    tmp.clear();
    for(auto v:ans){
      idx = digits[i]-'0';
      if(idx<2) continue;
      tmp.push_back(v+m[idx][0]);
      tmp.push_back(v+m[idx][1]);
      tmp.push_back(v+m[idx][2]);
      if(idx==7||idx==9) tmp.push_back(v+m[idx][3]);
    }
    swap(ans,tmp);
  }
  return ans;
}

int main(){
  auto a1 = letterCombinations("23"); 
  for(auto v:a1) cout << v << " "; cout << endl;
  return 0;
}
