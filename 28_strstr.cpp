#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <cstring>

using namespace std;

// Recommend
int strStr(string h, string n) {
  int j;
  if(n.size()==0)
    return 0;
  for(int i=0;i<=(int)(h.length()-n.length());i++)
  {
    for(j=0;j<n.length();j++)
    {
      if(h[i+j]!=n[j])
        break;
    }
    if(j==n.length())
      return i;
  }
  return -1;
}

int strStr2(string haystack, string needle) {
  if(haystack.length()==0 && needle.length()==0 ) return 0;
  if(haystack.length()==0) return -1;
  if(needle.length()  ==0) return 0;
  if(haystack.length() < needle.length()) return -1;

  bool debug = false;
  int i=0,j=0,t;

  map<char, int> m1, m2;

  // Check char freq
  while(haystack[i]!='\0') {
    if ( m1.find(haystack[i])==m1.end() ) {
      m1.insert(make_pair(haystack[i],1));
    } else {
      m1[haystack[i]]++;
    }
    i++;
  }

  i = 0;
  while(needle[i]!='\0') {
    if ( m1.find(needle[i])==m1.end() ) {
      cout << needle[i] << " not found." << endl;
      return -1;
    }
    if ( m2.find(needle[i])==m2.end() ) {
      m2.insert(make_pair(needle[i],1));
    } else {
      m2[needle[i]]++;
    }
    i++;
  }
 
  i = j = 0;
  while(haystack[i]!='\0') {
    j = 0;
    if(haystack[i]==needle[j]){
      if ( debug ) cout << haystack[i] << " vs " << needle[j] << endl;
      t = i; t++; j++; 
      while( needle[j]!='\0' && haystack[t]==needle[j]) { 
        if ( debug ) cout << " -> " << haystack[t] << " vs " << needle[j] << endl;
        t++; j++;
      }
      if ( debug ) cout << " => " << haystack[t] << " vs " << needle[j] << endl;
      if(needle[j]=='\0'){
        return i;
      }
    }
    i++;
  }
  return -1;
}

int main(){

  //string s1 = "absabdab"; 
  //cout << strStr(s1, "abd") << endl;
  cout << strStr("a", "a") << endl;

  return 0;
}
