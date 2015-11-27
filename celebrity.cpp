#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

bool knows(int a, int b);

// https://leetcode.com/discuss/56350/straight-forward-c-solution-with-explaination
int findCelebrity(int n) {
  if(n<=1) return n;

  int candidate = 0;
  for(int i=1; i<n; i++){
    if ( !knows(i,candidate) ){
      candidate = i;
    }
  }

  for(int j=n-1; j>=0; j--){
    if(j== candidate) continue;
    if( !knows(j,candidate) || knows(candidate,j) ){
      //if j does not know candidate, or candidate knows j, return -1;
      return -1;
    }
  }

  return candidate;
}

int findCelebrity(int n) {
  if (n==0) return -1;
  if (n==1) return  0;
  int idx = 0;
  vector<bool> f(n,true);
  for(int i=1;i<n;i++){
    if(!f[i]) continue;
    if(!knows(i,0)){
      // i is possible
      bool isCelebrity = true;
      // check he don't know others
      for(int j=0;j<n;j++){
        if(!f[j] || j==i) continue;
        if(knows(i,j)) {
          isCelebrity = false;
          break;
        }
        f[j] = false;
      }
      if(isCelebrity) {
        // check all other knew it 
        for(int j=0;j<n;j++){
          if(j==i) continue;
          if(!knows(j,i)) {
            isCelebrity = false;
            break;
          }
          f[j] = false;
        }
      }
      if(isCelebrity) return i;
    }
  }

  if(!f[0]) return -1;

  int i = 0;
  bool isCelebrity = true;
  // check he don't know others
  for(int j=1;j<n;j++){
    if(knows(i,j)) {
      isCelebrity = false;
      break;
    }
  }
  if(isCelebrity) {
    // check no other knew it 
    for(int j=0;j<n;j++){
      if(j==i) continue;
      if(!knows(j,i)) {
        isCelebrity = false;
        break;
      }
    }
  }
  if(isCelebrity) return i;

  return -1;
}

int main(){

  return 0;
}
