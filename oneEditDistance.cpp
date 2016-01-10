#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

bool isOneEditDistance(string s, string t) {
  if(s.size()>t.size()) return isOneEditDistance(t,s);
  if(t.size()-s.size()>1) return false;
  bool dif = false;
  int i = 0, j = 0;
  while(i<s.size()){
    if(s[i]!=t[j]) {
      // Already has difference, then this pos have second one. 
      // Return false directly. 
      if ( dif ) 
        return false;
      
      // Encounter difference in this pos 
      // Shift idx of string t and do another check again. 
      if ( s.size()!=t.size() ) { 
        j++;
        // If it fails, we got the second edit distance. 
        // Return false. 
        if ( s[i]!=t[j] ) 
          return false;
      }
      dif = true;
    }
    i++;
    j++;
  }
  if ( !dif && s.size()!=t.size() ) dif = ~dif; // Last one is edit distance
  return dif;
}

int main(){
  cout << isOneEditDistance("kitten", "sitten") << " 1" << endl;
  cout << isOneEditDistance("kitten", "sitteg") << " 0" << endl;
  cout << isOneEditDistance("sitten", "sitteng") << " 1" << endl;
  cout << isOneEditDistance("sittej", "sitteng") << " 1" << endl;
  cout << isOneEditDistance("a", "ba") << " 1" << endl;
  cout << isOneEditDistance("ab", "acb") << " 1" << endl;
  cout << isOneEditDistance("", "") << " 0" << endl;
  cout << isOneEditDistance("a", "") << " 1" << endl;
  return 0;
}
