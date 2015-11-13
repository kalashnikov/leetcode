#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
#include <set>

using namespace std;

// 124ms
vector<vector<string>> groupAnagrams2(vector<string>& strs) {
  vector<vector<string>> ans; 
  if(strs.size()==0) return ans;
  unordered_map<string, vector<string>> result; 

  for(int i=0;i<strs.size();i++){
    vector<int> vs(26,0);
    for(int j=0;j<strs[i].length();j++){
      vs[strs[i][j]-'a']++;
    }
    
    // Gen key: Slow
    stringstream ss;
    int j = vs.size()-1;
    while(j>=0&&vs[j]==0) j--; 
    for(int i=0;i<=j;i++) 
      ss << vs[i] << "_";
    //cout << ss.str() << " " << strs[i] << endl;

    if(result.count(ss.str())) {
      result[ss.str()].push_back(strs[i]);
    } else {
      vector<string> tmp{strs[i]};
      result[ss.str()] = tmp;
    }
  }

  for(auto v:result){
    sort(v.second.begin(),v.second.end());
    ans.push_back(v.second);
  }
  return ans; 
}

// General sort takes O(nlogn) time. 
// In this problem, since the string only contains lower-case alphabets, 
// we can write a sorting function using counting sort (O(n) time) to speed up the sorting process.
string strSort(string& s) {
	int count[26] = {0}, n = s.length();
	for (int i = 0; i < n; i++)
		count[s[i] - 'a']++;
	int p = 0;
	string t(n, 'a');
	for (int j = 0; j < 26; j++)
		for (int i = 0; i < count[j]; i++)
			t[p++] += j;
	return t;
} 

// 76 ms
// The idea is to use an unordered_map to store those strings that are anagrams. 
// We use the sorted string as the key and the string itself as the value. 
// The strings are stored in a multiset since there may be duplicates. 
// Moreover, multiset will sort them by default as we desire.
// https://leetcode.com/discuss/51129/10-lines-76ms-easy-c-solution-updated-function-signature
vector<vector<string>> groupAnagrams(vector<string>& strs) {
	unordered_map<string, multiset<string>> mp;
	for (string s : strs) {
		string t = strSort(s);
		mp[t].insert(s);
	}
	vector<vector<string>> anagrams;
	for (auto m : mp) { 
		vector<string> anagram(m.second.begin(), m.second.end());
		anagrams.push_back(anagram);
	}
	return anagrams;
}

int main(){
  vector<string> i1 {"eat", "tea", "tan", "ate", "nat", "bat"};
  //sort(i1.begin(),i1.end());
  auto a1 = groupAnagrams(i1);
  for(auto v:a1) {
    for(auto vv:v) 
      cout << vv << " "; 
    cout << endl;
  } 
  cout << endl;
  return 0;
}
