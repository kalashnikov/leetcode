#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

string toShifted(const string s){
  if(s.length()==0) return string();
  if(s[0]=='a') return string(s); 
  int scnt = s[0]-'a';
  string a(s);
  for(int i=1;i<s.length();i++){
    a[i] = ((s[i]-scnt)<'a') ? s[i]+26-scnt : s[i]-scnt;
  }
  a[0]='a';
  return a;
}

vector<vector<string>> groupStrings(vector<string>& strings) {
  unordered_map<string, vector<string>> db;
 
  string key;
  for(auto v:strings){
    key = toShifted(v);
    if(db.count(key)){
      db[key].push_back(v); 
    } else {
      db[key]=vector<string>{v};
    }
  }

  vector<vector<string>> ans; 
  for(auto v:db){
    sort(v.second.begin(),v.second.end());
    ans.push_back(v.second);
  }
  return ans;
}

int main(){

  vector<string> i1 {"abc", "bcd", "acef", "xyz", "az", "ba", "a", "z", "ab"};
  auto v1 = groupStrings(i1); 
  for(auto v:v1){ 
    for(auto vv:v)
      cout << vv << " ";
    cout << endl;
  }
  cout << toShifted(string("ba")) << endl;
  return 0;
}
