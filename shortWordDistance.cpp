#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

// TLE
class WordDistance2 {
  unordered_map<string, int> result;
  public:
    WordDistance2(vector<string>& words) {
      result.reserve(2*words.size());
      string p;
      for(int i=0;i<words.size()-1;i++){ 
        for(int j=i+1;j<words.size();j++){
          if(words[i]==words[j]) continue;
          p = (words[i]>words[j]) ? (words[j]+"_"+words[i]) : (words[i]+"_"+words[j]);
          if(result.count(p)) {
            result[p] = min(result[p], j-i);
          } else { 
            result[p] = j-i;
          }
        }
      }
    }

    int shortest(string word1, string word2) {
      string p = word1 > word2 ? (word2+"_"+word1) : (word1+"_"+word2);
      return result[p];
    }
};

class WordDistance {
  unordered_map<string,vector<int>> db;
  public:
    WordDistance(vector<string>& words) {
      db.reserve(words.size());
      for(int i=0;i<words.size();i++){
        if(db.count(words[i])) { 
          db[words[i]].push_back(i); 
        } else {
          db[words[i]] = vector<int>{i};
        }
      }
    }

    int shortest(string word1, string word2) {
      int dif = INT_MAX;
      auto itr1 = db[word1].cbegin(),eitr1 = db[word1].cend();
      auto itr2 = db[word2].cbegin(),eitr2 = db[word2].cend();
      while(itr1!=eitr1 && itr2!=eitr2){
        dif = min(dif,abs(*itr1-*itr2));
        if(dif==1) return 1;
        if(*itr1<*itr2) itr1++; else itr2++;
      }
      return dif;
    }
};

int shortestWordDistance(vector<string>& words, string word1, string word2) {
  bool same = (word1==word2);
  int idx1 = -1, idx2 = -1, dif = INT_MAX;
  for(int i=0;i<words.size();i++){
    if(words[i]==word1) { 
      if(idx1!=-1 &&  same) dif = min(dif,i-idx1); 
      idx1=i; 
      if(idx2!=-1 && !same) dif = min(dif,i-idx2); 
    }
    if(words[i]==word2) { 
      idx2=i; 
      if(idx1!=-1 && !same) dif = min(dif,i-idx1); 
    }
  }
  return dif;
}

int main(){
  vector<string> i1 {"practice", "makes", "perfect", "coding", "makes"};
  cout << shortestWordDistance(i1, "makes", "coding") << " 1" << endl;
  cout << shortestWordDistance(i1, "makes", "makes") << " 3"  << endl;

  WordDistance wordDistance(i1);
  cout << wordDistance.shortest("coding", "practice") << " 3" << endl;
  cout << wordDistance.shortest("makes", "coding")    << " 1" << endl;
  return 0;
}
