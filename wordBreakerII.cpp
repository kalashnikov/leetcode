#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <list>

using namespace std;

class Node{
  public: 
    char ch;
    unordered_map<char,Node*> db;
    Node(char c):ch(c) {} 
};

vector<string> wordBreak1(string s, unordered_set<string>& wordDict) {
  vector<string> ans;
  if ( s.length()==0 ) return ans;
  
  Node root(' ');
  Node *ptr = &root;

  // Init data structure
  for(auto w:wordDict){
    ptr = &root;
    for(int i=0;i<w.length();i++){
      if(ptr->db.find(w[i])==ptr->db.end()){
        Node ntmp(w[i]);
        ptr->db[w[i]] = &ntmp;
        ptr = &ntmp;
      } else {
        ptr = ptr->db[w[i]]; 
      }
    }
  }

  return ans;
}

void helper(vector<string>& ans, string cur_s, string cand_s, unordered_map<char, vector<string>>& db){
  if( db.find(cur_s[0])==db.end() ) return;
  for(auto pos_s: db[cur_s[0]]) {
    int i = 1;
    while(pos_s[i]!='\0'&&pos_s[i]==cur_s[i]) i++;
    if( i != pos_s.length() ) continue; 
    string fs =  (cand_s=="")? pos_s:(cand_s+ " " + pos_s);
    if ( cur_s.length() == pos_s.length() ) {
      ans.push_back(fs);
      return;
    }
    //cout << "Call: " << cur_s.substr(pos_s.length()) << " & " << cand_s + " " + pos_s << endl;
    helper(ans, cur_s.substr(pos_s.length()), fs, db); 
  }
}

vector<string> wordBreak2(string s, unordered_set<string>& wordDict) {
  vector<string> ans;
  if ( s.length()==0 ) return ans;
 
  // Init data structure
  unordered_map<char, vector<string>> db;
  for(auto w:wordDict){
    if ( w.length()==0 ) continue;
    if ( db.find(w[0])==db.end() ) {
      vector<string> tvs { w };
      db[w[0]] = tvs;
    } else { 
      db[w[0]].push_back(w);
    }
  }

  // Recursive call
  helper(ans, s, "", db);
  return ans;
}


vector<string> combine(string word, vector<string> prev){
  for(int i=0;i<prev.size();++i){
    prev[i]+=" "+word;
  }
  return prev;
}

vector<string> wordBreak(string s, unordered_set<string>& dict) {
  static unordered_map<string, vector<string>> m;
  if(m.count(s)) return m[s]; //take from memory
  vector<string> result;
  if(dict.count(s)){ //a whole string is a word
    result.push_back(s);
  }
  for(int i=1;i<s.size();++i){
    string word=s.substr(i);
    cout << word << " | " << s << endl;
    if(dict.count(word)){
      string rem=s.substr(0,i);
      cout << "    => call rem: " << rem << endl;
      vector<string> prev=combine(word,wordBreak(rem,dict));
      cout << "### Result: "; for(auto v:prev) cout << v << ","; cout << endl << endl; 
      result.insert(result.end(),prev.begin(), prev.end());
    }
  }
  m[s]=result; //memorize
  return result;
}

int main(){
  unordered_set<string> w1 {"cat", "cats", "and", "sand", "dog"};
  auto a1 = wordBreak("catsanddog", w1);
  for(auto v:a1) cout << v << endl;

  //unordered_set<string> w2 {"a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"};
  //auto a2 = wordBreak("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab", w2);
  //for(auto v:a2) cout << v << endl;
  return 0;
}
