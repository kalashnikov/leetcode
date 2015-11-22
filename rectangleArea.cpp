#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

// https://leetcode.com/discuss/43549/just-another-short-way
int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
  int left = max(A,E), right = max(min(C,G), left);
  int bottom = max(B,F), top = max(min(D,H), bottom);
  return (C-A)*(D-B) - (right-left)*(top-bottom) + (G-E)*(H-F);
}

int interArea(int A, int B, int C, int D, int E, int F, int G, int H){
  if( A>E ) return interArea(E,F,G,H,A,B,C,D);
  if( C<E || D<F || A>G || B>H ) return 0;
  return (min(G,C)-max(A,E))*(min(H,D)-max(B,F)); 
}

int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
  if( A==C || B==D ) return (G-E)*(H-F);
  if( E==G || F==H ) return (C-A)*(D-B);
  return (C-A)*(D-B)+(G-E)*(H-F)-interArea(A,B,C,D,E,F,G,H);
}

int main(){
  cout << computeArea(-3,0,3,4,0,-1,9,2) << endl;
  cout << computeArea(0,0,0,0,-1,-1,1,1) << endl;
  cout << computeArea(-2,-2,2,2,3,3,4,4) << endl;
  cout << computeArea(-5,4,0,5,-3,-3,3,3) << endl;
  return 0;
}
