#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

// P   A   H   N
// A P L S I I G
// Y   I   R
// 24ms
string convert2(string s, int numRows) {
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

// 16ms
string convert(string s, int numRows) {
  if(s.length()<2 || numRows==1) return s;

  string result = "";
  int j, k, n = s.length(), inv = 2*numRows - 2;
  for(int i=0;i<numRows;i++){
    if(i==0||i==numRows-1){ 
      j = i;
      while(j<n){
        result.push_back(s[j]);
        j += inv;
      }
    } else {  
      j = i;
      k = inv - j;
      while(j<n){
        result.push_back(s[j]);
        if ( k < n ) result.push_back(s[k]);
        j += inv;
        k += inv;
      }
    }
  }
  return result;
}

// 16ms
string convert(string s, int numRows) {
  if(s.length()<2 || numRows==1) return s;

  string result = ""; 
  int j, k, n = s.length(), inv = 2*numRows - 2;
  j = 0;
  while(j<n){
    result.push_back(s[j]);
    j+= inv;
  }
  for(int i=1;i<numRows-1;i++){
    j = i;
    k = inv - j;
    while(j<n){
      result.push_back(s[j]);
      j += inv;
      if ( k < n ) { result.push_back(s[k]); k+=inv; } 
    }
  }
  j = numRows-1;
  while(j<n){
    result.push_back(s[j]);
    j+= inv;
  }
  return result;
}

int main(){
  cout << convert("PAYPALISHIRING", 3) << endl;
  cout << "PAHNAPLSIIGYIR" << endl; 
  return 0;
}
