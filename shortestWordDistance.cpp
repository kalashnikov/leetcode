#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

int shortestDistance1(vector<string>& words, string word1, string word2) {
  if(words.size()==0) return 0;
  unordered_map<string,vector<int> > db;
  for(int i=0;i<words.size();i++){
    if(db.count(words[i]))
      db[words[i]].push_back(i);
    else {
      vector<int> t { i };
      db[words[i]] = t;
    }
  }

  int ans = words.size();
  vector<int>& v1 = db[word1];
  vector<int>& v2 = db[word2];
  for(int i=0;i<v1.size();i++)
    for(int j=0;j<v2.size();j++)
      ans = min(ans,abs(v1[i]-v2[j]));

  return ans;
}

int shortestDistance(vector<string>& words, string word1, string word2) {
  int pos1 = -1, pos2 = -1, ans = words.size();
  for(int i=0;i<words.size();i++){
    if(words[i]==word1) pos1=i;
    if(words[i]==word2) pos2=i;
    if(pos1!=-1&&pos2!=-1)
      ans = min(ans,abs(pos1-pos2)); 
  }
  return ans; 
}

int main(){
  vector<string> s1 {"practice", "makes", "perfect", "coding", "makes" };
  cout << shortestDistance(s1, "practice", "coding") << endl;
  cout << shortestDistance(s1, "makes", "coding") << endl;
  return 0;
}
