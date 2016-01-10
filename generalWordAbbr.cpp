#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

vector<string> generateAbbreviations(string word) {
  if(word.size()==0) return vector<string>{""};
  vector<string> ans{"1","1"};
  ans[0][0] = word[0];
  for(int idx = 1; idx < word.size(); idx++) { 
    vector<string> tmp(ans);
    tmp.insert(tmp.end(), ans.begin(), ans.end()); 

    int i = 0;
    for(;i<tmp.size()/2; i++)
      tmp[i].push_back(word[idx]);

    for(;i<tmp.size(); i++) {
      if(tmp[i].back()=='9'){
        tmp[i].back() = '1'; 
        tmp[i].push_back('0'); 
      } else if(tmp[i].back()>='0' && tmp[i].back()<='8')
        tmp[i].back()+=1;
      else     
        tmp[i].push_back('1');
    }
    
    ans.swap(tmp);
    //cout << ans.size() << ": ";
    //for(auto v:ans) cout << v << " ";
    //cout << endl;
  }
  return ans;
}

int main(){

  //auto a1 = generateAbbreviations("dictionary"); 
  auto a1 = generateAbbreviations("word"); 
  for(auto v:a1) 
    cout << v << " "; 
  cout << endl;

  return 0;
}
