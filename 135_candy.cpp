#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

int candy(vector<int>& ratings) {
  if ( ratings.size()<2 ) return ratings.size();

  // Hint from haoel
  // https://github.com/haoel/leetcode/blob/master/algorithms/cpp/candy/candy.cpp
  
  /* 1) Go through the ratings from left to right.
  **
  **    Find the each increasing sub-array, giving the minimal candy     
  **
  **    ratings[] = { 5, 6, 7,   4,   1, 2, 3,   2,   1, 7 } 
  **                  ------>    ->   ------>    ->   --->
  **      candy[] = { 1, 2, 3,   1,   1, 2, 3,   1,   1, 2 }
  */
  vector<int> ans(ratings.size(), 1);
  for( int i=1; i<ratings.size(); i++ ){
    if ( ratings[i] > ratings[i-1] ) ans[i] = ans[i-1]+1;
  }
 
  /* 2) Go through the raings from right to left.
  *
  *          ratings[] = { 5,   6,   7, 4, 1,   2,   3, 2, 1,   7 } 
  *                        <-   <-   <------    <-   <------    <-
  *       prev_candy[] = { 1,   2,   3, 1, 1,   2,   3, 1, 1,   2 }
  *                                     +1              +1
  *            candy[] = { 1,   2,   3, 2, 1,   2,   3, 2, 1,   2 }
  */
  for( int i=ratings.size()-2; i>-1; i-- ){
    if ( ratings[i] > ratings[i+1] && ans[i] <= ans[i+1] ) ans[i] = ans[i+1]+1;
  }

  int sum = 0;
  for( int i=0; i<ans.size(); i++ ){
    sum+=ans[i];
  }
  return sum;
}

void update(vector<int>& ratings, vector<int>& ans, int idx){
  if(idx<0) return;
  if(ratings[idx]>ratings[idx+1] && ans[idx]<=ans[idx+1]){
    ans[idx] = ans[idx+1]+1;
    update(ratings,ans, idx-1);
  }
}

int candy2(vector<int>& ratings) {
  if ( ratings.size()<2 ) return ratings.size();

  // Check for corner case 
  // Decremental array
  bool c = true;
  for ( int i=1; i<ratings.size();i++){
    if ( ratings[i]>ratings[i-1] ) { 
      c = false;
      break;
    }
  }
  if ( c ) reverse(ratings.begin(),ratings.end());

  vector<int> ans(ratings.size(), 1);
  for( int i=1; i<ratings.size(); i++ ){
    if ( ratings[i] > ratings[i-1] ) ans[i] = ans[i-1]+1;
    if ( ratings[i-1] > ratings[i] ) update(ratings,ans,i-1); // Backward update
  }

  int sum = 0;
  for( int i=0; i<ans.size(); i++ ){
    sum+=ans[i];
  }
  return sum;
}

int main(){
  vector<int> v0 { 2,2 };
  cout << candy(v0) << endl;

  vector<int> v1 { 5,2,3,1,5,7 };
  cout << candy(v1) << endl;

  vector<int> v2 (12000,0);
  for(int i=0;i<12000;i++) 
    v2[i] = 12000 - i;
  cout << candy(v2) << endl;
  
  vector<int> v3 { 1,2,4,4,3 };
  cout << candy(v3) << endl;

  return 0;
}
