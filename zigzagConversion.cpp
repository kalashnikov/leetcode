#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

// P   A   H   N
// A P L S I I G
// Y   I   R
string convert(string s, int numRows) {
  if(s.length()<2) return s;
  if(numRows==1  ) return s;

  int j, k, inv = 2*numRows - 2;
  vector<string> ss(numRows,""); 
  for(int i=0;i<s.length();i+=inv){
    // Zig 
    for(j=0;j<numRows;j++)
      if((i+j)<s.length()) 
        ss[j].push_back(s[i+j]);
    
    // Zag
    for(k=numRows-2;k>0;k--,j++)
      if((i+j)<s.length()) 
        ss[k].push_back(s[i+j]);
  }

  s.clear(); 
  for(int i=0;i<numRows;i++) 
    s.append(ss[i]);
  return s;
}

int main(){
  cout << convert("PAYPALISHIRING", 3) << endl;
  cout << "PAHNAPLSIIGYIR" << endl; 
  return 0;
}
