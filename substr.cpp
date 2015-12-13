#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

// http://www-igm.univ-mlv.fr/~lecroq/string/node5.html 
// In the following function KR all the multiplications by 2 are implemented by shifts. 
// Furthermore, the computation of the modulus function is avoided by using the implicit modular arithmetic given by the hardware that forgets carries in integer operations. 
// So, q is chosen as the maximum value for an integer.
int RabinKarp2(const string& t, const string& s) {
  if ( s.size() > t.size() ) return -1;

  int m = t.size(), n = s.size();

  int power_s = 1;
  int t_hash = 0, s_hash = 0;
  for(int i=0;i<n;i++){
    power_s = i ? (power_s << 1) : 1; 
    t_hash  = ( ( t_hash << 1 ) + t[i] ); 
    s_hash  = ( ( s_hash << 1 ) + s[i] );
  }

  for(int i=0;i<=m-n;i++){
    if(t_hash == s_hash && !t.compare(i, s.size(), s) ) {
      return i;
    }
    t_hash = ( ( t_hash - t[i] * power_s ) << 1 ) + t[i+n];
  }
  return -1; 
}

int RabinKarp(const string& t, const string& s) {
  const int kBase = 26, kMod = 997;
  if ( s.size() > t.size() ) return -1;

  int power_s = 1;
  int t_hash = 0, s_hash = 0;
  for(int i=0;i<s.size();i++){
    power_s = i ? (power_s * kBase % kMod) : 1; 
    t_hash  = ( t_hash * kBase + t[i] ) % kMod; 
    s_hash  = ( s_hash * kBase + s[i] ) % kMod;
  }

  for(int i=s.size();i<t.size();i++){
    if(t_hash == s_hash && !t.compare(i - s.size(), s.size(), s) ) {
      return i - s.size();
    }

    t_hash -= (t[i-s.size()]*power_s) % kMod;
    if ( t_hash < 0 ) t_hash += kMod; 
    t_hash  = (t_hash * kBase + t[i]) % kMod; 
  }
  if(t_hash == s_hash && !t.compare(t.size() - s.size(), s.size(), s) ) {
    return t.size() - s.size();
  } 
  return -1; 
}

int main(){

  string t1 = "GACGCCA"; 
  string s1 = "CGC"; 
  cout << RabinKarp2(t1,s1) << " 2" << endl;
  
  string t2 = "asbsetgs"; 
  string s2 = "tgs"; 
  cout << RabinKarp2(t2,s2) << " 5" << endl;
  return 0;
}
