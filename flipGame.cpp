#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

vector<string> generatePossibleNextMoves(string s) {
  vector<string> ans;
  if(s.length()<2) return ans;
  for(int i=1;i<s.length();i++){
    if(s[i]=='+' && s[i-1]=='+'){
      string _s(s); 
      _s[i]=_s[i-1]='-';
      ans.push_back(_s);
    }
  }
  return ans;
}

bool canWin_formula_fail(string s) {
  if ( s.length() < 2 ) return false;

  int tcnt = 0;
  int count_a = 0, count_b = 0;
  bool section = false;
  for(int i=0;i<s.length();i++){
    if ( s[i]=='+' ) {
      section = true;
      tcnt++;
    } else {
      // '-'
      if (section) { 
        section = false;
        if ( tcnt%4==1 ) count_b++; 
        else count_a++;
      }
    }
  }
  if (section) { 
    section = false;
    if ( tcnt%4==1 ) count_b++; 
    else count_a++;
  }
  //count_a %= 2; 
  //count_b %= 2;
  //cout << count_a << " " << count_b << endl;
  if ( count_b != 0 ) return false;
  if ( count_a > 0 ) return true;
  if ( count_a % 2 == 1 ) return true;
  return false;
}


bool canWin(string s);

bool existWinMoves(string s){
  auto move = generatePossibleNextMoves(s); // Opponent's turn
  if ( move.size()==0 ) return true;
  for(auto v:move){
    if ( !canWin(v) ) { 
      return false;
    }
  }
  return true;
}

bool canWin2(string s) {
  static unordered_map<string,bool> cache; // Memorization: 684ms -> 60ms
  if ( s.length() < 2 ) return false;
  if ( cache.find(s)!=cache.end() ) return cache[s];
  auto move = generatePossibleNextMoves(s);
  if ( move.size()==0 ) return false; 
  for(auto v:move){ 
    if ( existWinMoves(v) ){
      cache[s] = true;
      return true;
    }
  }
  cache[s] = false;
  return false;
}

// 
// @ stellari
// https://leetcode.com/discuss/64344/theory-matters-from-backtracking-128ms-to-dp-0ms
int len;
string ss;
bool canWin(string s) {
  len = s.size();
  ss = s;
  return canWin();
}

bool canWin() {
  for (int is = 0; is <= len-2; is++) {
    if (ss[is] == '+' && ss[is+1] == '+') {
      ss[is] = '-'; ss[is+1] = '-';
      bool wins = !canWin(); 
      ss[is] = '+'; ss[is+1] = '+';
      if (wins) return true;
    }
  }
  return false;
}

/*  
int firstMissingNumber(unordered_set<int> lut) {
    int m = lut.size();
    for (int i = 0; i < m; ++i) {
        if (lut.count(i) == 0) return i;
    }
    return m;
}

bool canWin(string s) {
	int curlen = 0, maxlen = 0;
	vector<int> board_init_state;
	for (int i = 0; i < s.size(); ++i) {    
		if (s[i] == '+') curlen++;              // Find the length of all continuous '+' signs
		if (i+1 == s.size() || s[i] == '-') {
			if (curlen >= 2) board_init_state.push_back(curlen);    // only length >= 2 counts
			maxlen = max(maxlen, curlen);       // Also get the maximum continuous length
			curlen = 0;
		}
	}          // For instance ++--+--++++-+ will be represented as (2, 4)
	vector<int> g(maxlen+1, 0);    // Sprague-Grundy function of 0 ~ maxlen
	for (int len = 2; len <= maxlen; ++len) {
		unordered_set<int> gsub;    // the S-G value of all subgame states
		for (int len_first_game = 0; len_first_game < len/2; ++len_first_game) {
			int len_second_game = len - len_first_game - 2;
			// Theorem 2: g[game] = g[subgame1]^g[subgame2]^g[subgame3]...;
			gsub.insert(g[len_first_game] ^ g[len_second_game]);
		}
		g[len] = firstMissingNumber(gsub);
	}

	int g_final = 0;
	for (auto& s: board_init_state) g_final ^= g[s];
	return g_final != 0;    // Theorem 1: First player must win iff g(current_state) != 0
}
// @ StefanPochmann
bool canWin(string s) {
    replace(s.begin(), s.end(), '-', ' ');
    istringstream in(s);
    int G = 0;
    vector<int> g;
    for (string t; in >> t; ) {
        int p = t.size();
        while (g.size() <= p) {
            string x = t;
            int i = 0, j = g.size() - 2;
            while (i <= j)
                x[g[i++] ^ g[j--]] = '-';
            g.push_back(x.find('+'));
        }
        G ^= g[p];
    }
    return G;
}
*/

int main(){
  //auto a1 = generatePossibleNextMoves("++++");
  //for(auto v:a1) cout << v << endl; cout << endl;

  cout <<  "--"          << " -> " << canWin("--")          << endl;
  cout <<  "+++++"       << " -> " << canWin("+++++")       << endl;
  cout <<  "++++-++++++" << " -> " << canWin("++++-++++++") << endl;
  cout <<  "++++-++++"   << " -> " << canWin("++++-++++")   << endl;

  return 0;
}
