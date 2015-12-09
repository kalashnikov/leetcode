#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

// Beautiful code by Stefan 
// https://leetcode.com/discuss/48468/1-11-lines-python-9-lines-c
vector<int> diffWaysToCompute(string input) {
  vector<int> output;
  for (int i=0; i<input.size(); i++) {
    char c = input[i];
    if (ispunct(c))
      for (int a : diffWaysToCompute(input.substr(0, i)))
        for (int b : diffWaysToCompute(input.substr(i+1)))
          output.push_back(c=='+' ? a+b : c=='-' ? a-b : a*b);
  }
  if ( output.size() ) {
    cout << input << " : ";
    for(auto v:output) cout << v << " "; 
    cout << endl;
  }
  return output.size() ? output : vector<int>{stoi(input)};
}

int main(){
  auto a1 = diffWaysToCompute("2-1-1");
  for(auto v:a1) cout << v << " "; cout << endl;

  auto a2 = diffWaysToCompute("2*3-4*5");
  for(auto v:a2) cout << v << " "; cout << endl;
  
  return 0;
}
