#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

class TrieNode {
public:
    // Initialize your data structure here.
    TrieNode(): isWord(false), size(0){
      //vec = new vector<TrieNode*>(26,NULL);
      memset(ary, 0, 26*sizeof(TrieNode*));
    }
  
    int size;
    bool isWord;
    TrieNode* ary[26];                    // 56ms
    //vector<TrieNode*> *vec;             // 84ms
    //unordered_map<char,TrieNode*> db;   // 156ms
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
      aux = root;
      for(auto v:word) {
        // unordered_map 
        //if(!aux->db.count(v)) {
        //  aux->db[v] = new TrieNode();
        //}
        //aux = aux->db[v];
        
        // Vector 
        //if((*aux->vec)[v-'a']==NULL) {
        //  (*aux->vec)[v-'a'] = new TrieNode();
        //}
        //aux = (*aux->vec)[v-'a'];

        if(aux->ary[v-'a']==0) {
          aux->ary[v-'a'] = new TrieNode();
        }
        aux = aux->ary[v-'a'];
      }
      aux->isWord = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
      aux = root;
      for(auto v:word) { 
        if(aux->ary[v-'a']==0) return false; 
        aux = aux->ary[v-'a'];
      }
      return aux->isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
      aux = root;
      for(auto v:prefix) { 
        if(aux->ary[v-'a']==0) return false; 
        aux = aux->ary[v-'a'];
      }
      return true;
    }

private:
    TrieNode *root, *aux;
};

// 80ms
class WordDictionary {

public:
    WordDictionary() {
      root = new TrieNode();
    } 

    // Adds a word into the data structure.
    void addWord(string word) {
      aux = root;
      for(auto v:word) {
        if(aux->ary[v-'a']==0) {
          aux->ary[v-'a'] = new TrieNode();
          aux->size++;
        }
        aux = aux->ary[v-'a'];
      }
      aux->isWord = true;
      lens.insert(word.length());
    }

    bool searchTrie(string& word, int lo, int hi, TrieNode* aux){
      for(int i=lo;i<hi;i++) {
        if(word[i]=='.') {
          // Make sure aux->ary is not empty 
          if( aux->size == 0 ) return false;
          for(auto vv: aux->ary) {
            if(vv==0) continue;
            if(searchTrie(word,i+1,hi,vv)) 
              return true;
          }
          return false;
        }
        if(aux->ary[word[i]-'a']==0) return false; 
        aux = aux->ary[word[i] -'a'];
      }
      // if lo==hi, we still need to check this is word or not.
      return aux->isWord;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
      if(!lens.count(word.length())) return false;
      return searchTrie(word, 0, word.length(), root); 
    }

private:
    TrieNode *root, *aux;
    set<int> lens;
};

int main(){

// Your Trie object will be instantiated and called as such:
  Trie trie;
  trie.insert("stack");
  trie.insert("stacks");
  trie.insert("star");
  cout << trie.search("star") << " 1" << endl;
  cout << trie.startsWith("sta") << " 1" << endl;
  cout << trie.startsWith("stt") << " 0" << endl;
  cout << trie.search("sta") << " 0" << endl;

  cout << "===========" << endl;

  WordDictionary wd; 
  wd.addWord("s");
  cout << wd.search(".") << " 1" << endl;
  wd.addWord("star");
  wd.addWord("stack");
  wd.addWord("stacks");
  cout << wd.search("sta.") << " 1" << endl;
  cout << wd.search("stack") << " 1" << endl;
  cout << wd.search("stac") << " 0" << endl;
  cout << wd.search("st.r") << " 1" << endl;
  cout << wd.search("..") << " 0" << endl;
  cout << wd.search("....") << " 1" << endl;
  cout << wd.search(".......") << " 0" << endl;

  return 0;
}
