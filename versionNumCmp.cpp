#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <sstream>

using namespace std;

// https://leetcode.com/discuss/23934/10-line-concise-solution-c
int compareVersion(string version1, string version2) {
  for(auto& w : version1) if (w == '.') w=' ';
  for(auto& w : version2) if (w == '.') w=' ';
  istringstream s1(version1), s2(version2);
  while(1) {
    int n1,n2;
    if (not(s1 >> n1) ) n1 = 0;
    if (not(s2 >> n2) ) n2 = 0;
    if (not s1 and not s2) return 0;
    if (n1<n2) return -1;
    if (n1>n2) return 1;
  }
}

int compareVersion2(string version1, string version2) {
  int n1 = version1.length(), n2 = version2.length();
  int idx1 = 0, idx2 = 0;
  bool validate1 = false, validate2 = false;
  while(idx1<n1 && idx2<n2){
    while(!validate1 && version1[idx1]=='0') idx1++;
    while(!validate2 && version2[idx2]=='0') idx2++;
    if(idx1>=n1||idx2>=n2) break;
    if(version1[idx1]!='.' && version2[idx2]=='.') return  1; 
    if(version1[idx1]=='.' && version2[idx2]!='.') return -1; 
    if(version1[idx1]>version2[idx2]) return (n1-idx1<n2-idx2&&version2[idx2+1]!='.') ? -1 :  1;
    if(version1[idx1]<version2[idx2]) return (n1-idx1>n2-idx2&&version1[idx1+1]!='.') ?  1 : -1;
    validate1 = (version1[idx1]=='.') ? false : true;
    validate2 = (version2[idx2]=='.') ? false : true;
    idx1++, idx2++;
  }
  while(version1[idx1]=='.'){
    idx1++;
    while(version1[idx1]=='0') idx1++;
  }  
  while(version2[idx2]=='.'){
    idx2++;
    while(version2[idx2]=='0') idx2++;
  }
  if(idx1<n1) return  1;
  if(idx2<n2) return -1;
  return 0;
}

int main(){

  cout << compareVersion("13.37", "13.37") << " 0" << endl;
  cout << compareVersion("13.37", "1.2") << " 1" << endl;
  cout << compareVersion("1.2", "1.1") << " 1" << endl;
  cout << compareVersion("1.1", "0.1") << " 1" << endl;
  cout << compareVersion("1.1", "13.37") << " -1" << endl;
  cout << compareVersion("01", "1") << " 0" << endl;
  cout << compareVersion("01.2", "1.02") << " 0" << endl;
  cout << compareVersion("1.1", "1.10") << " -1" << endl;
  cout << compareVersion("1.1", "1.1") << " 0" << endl;
  cout << compareVersion("1.0", "1.0") << " 0" << endl;
  cout << compareVersion("1.2", "1.10") << " -1" << endl;
  cout << compareVersion("1.30", "1.5") << "  1" << endl;
  cout << compareVersion("0.1", "0.0.1") << "  1" << endl;
  cout << compareVersion("1.0", "1") << "  0" << endl;
  cout << compareVersion("13.0", "13.0.8") << "  -1" << endl;
  cout << compareVersion("10.3", "11") << "  -1" << endl;

  cout << compareVersion("19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.00.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000",
"19.8.3.17.5.01.0.0.4.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0000.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.0.000000") << " 0" << endl;
  return 0;
}
