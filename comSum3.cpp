#include <iostream>
#include <vector>
#include <set>
#include <list>

using namespace std;

vector<vector<int>> combinationSum3_t1(int k, int n) {

  bool debug = true;

  int j = 0, sum = 0;
  double vote = k;
  int max = min(9,n);
  vector<int> ints(max,0);
  vector<vector<int>> ans;

  set<int> s;

  for(int i=ints.size()-1;i>-1;i--){
    if ( debug ) cout << "From " << i+1 << " : " << endl;
   
    list<int> stk;
    sum = 0, j = i, vote = k;

    while(j >-1 && vote!=0){
      if( j+1 > n ) continue;

      if ( debug ) {
        cout << " c1 |" << j+1 << " | v:" << vote << ", left:" << n-sum << " | stk: ";
        for(auto a:stk) cout << a << " "; 
        cout << endl;
      }
      
      if ( sum + j + 1 <= n ) { 
        sum += j+1; 
        stk.push_back(j+1);
        vote--;
      }
      
      if ( sum == n && vote != 0 ) { 
        if ( debug ) cout << " pop: " << stk.back() << endl;
        sum-=stk.back();
        stk.pop_back();
        vote++;
      }
      
      j--;
      
      if ( debug ) {
        cout << " c2 |" << j+1 << " | v:" << vote << ", left:" << n-sum << " | stk: ";
        for(auto a:stk) cout << a << " "; 
        cout << endl;
      }
    }
    if ( vote==0 && sum==n ) {
      int pro = 1;
      vector<int> ts;
      while(!stk.empty()){
        pro*=stk.back();
        ts.push_back(stk.back());
        stk.pop_back();
      }
      if ( s.find(pro)==s.end() ) {
        ans.push_back(ts);
        s.insert(pro);
      }
    }
  }
  return ans;
}

vector<vector<int>> combinationSum3_t2(int k, int n) {

  bool debug = true;

  int sum = 0;
  double vote = k;
  int max = min(9,n);
  vector<int> ints(max,0);
  vector<vector<int>> ans;

  set<int> s;

  for(int i=ints.size()-1;i>-1;i--){
    if ( i+1 > n ) continue;
    if ( i+1 == n && k==1 ) {
      vector<int> ts{i+1};
      ans.push_back(ts);
      continue;
    }
    
    if ( debug ) cout << "From " << i+1 << " : " << endl;
 
    sum = i+1, vote = k;
    if ( k==2 ) {
      for ( int j = i-1; j>-1; j--) { 
        if ( j+1+sum == n ) {
          vector<int> ts { j+1, i+1 };
          ans.push_back(ts);
          break;
        }
      }
    } else if ( k==3 ) { 
      for( int piv = (n-sum)/2-1; piv>-1; piv--){
        for ( int j = piv + 1; j<i; j++ ) {
          if ( piv + 1 + j + 1 == n - sum ) {
            vector<int> ts { piv+1, j+1, i+1 };
            ans.push_back(ts);
            break; 
          }
        }
      }
    }
  }
  return ans;
}

static set<int> product_set;
void cs3Helper(int idx, int k, int left, vector<vector<int>>& ans, list<int> stk){
  if ( ( left!=0 && k==0 ) || ( left==0 && k!=0 ) ) return;
  
  if ( left==0 && k==0 ) { 
    // Got solution, insert it
    
    stk.sort(); 

    //cout << "Push stack: ";
    //for(auto a:stk) cout << a << " "; 
    //cout << endl;
    //for(auto a:product_set) cout << a << " "; 
    //cout << endl;
   
    int pro = 1;
    vector<int> ts;
    while(!stk.empty()){
      pro *= stk.front();
      ts.push_back(stk.front());
      stk.pop_front();
    }
    if ( product_set.find(pro)==product_set.end() ) {
      product_set.insert(pro);
      ans.push_back(ts);
    }
  } else if (k!=0 && left!=0) {
    int limit = min(left, 9);
    for( int i=limit-1; i>-1; i--){
      if ( idx==i ) continue;
      if ( i+1 > stk.front() ) continue;
    
      bool dup = false;
      for(auto itr=stk.begin();itr!=stk.end();itr++){
        if ( i+1==*itr ){  
          dup=true;
          break;
        }
      }
      if ( dup ) continue; 
      
      list<int> stks(stk);
      stks.push_back(i+1);

      //cout << "Call(in): " << i+1 << " " << k-1 << " " << left-i-1 << " | ";
      //for(auto a:stks) cout << a << " "; 
      //cout << endl;
      
      cs3Helper(i, k-1, left-i-1, ans, stks);
    }
  }
}

vector<vector<int>> combinationSum3_try3(int k, int n) {

  product_set.clear(); 

  int limit = min(n, 9);
  vector<vector<int>> ans;
 
  for( int i=limit-1; i>-1; i--){
    list<int> stk;
    stk.push_back(i+1);
    //cout << "Call(ou): " << i+1 << " " << k-1 << " " << n-i-1 << " | ";
    //for(auto a:stk) cout << a << " "; 
    //cout << endl;
    cs3Helper(i, k-1, n-i-1, ans, stk);
  }

  return ans;
}

void backtrack(vector<vector<int>>& ans, vector<int>& path, int start, int k, int target){
  if ( target==0 && k==0 ){
    ans.push_back(path);
    return;
  } else {
    for(int i=start;i<=10-k && i<=target;i++){
      path.push_back(i);
      backtrack(ans,path,i+1,k-1,target-i);
      path.pop_back();
    }
  }
}

vector<vector<int>> combinationSum3(int k, int n) {
  vector<int> path;
  vector<vector<int>> ans;
  backtrack(ans,path,1,k,n);
  return ans;
}

int main(){
  auto r0 = combinationSum3(3,7);
  cout << "### ANS: " << endl;
  for(auto v:r0){
    for(auto vv:v)
      cout << vv << "|"; 
    cout << endl;
  }
  cout << endl << endl;

  auto r1 = combinationSum3(3,9);
  cout << "### ANS: " << endl;
  for(auto v:r1){
    for(auto vv:v)
      cout << vv << " ";
    cout << endl;
  }
  cout << endl << endl;
  
  auto r2 = combinationSum3(2,3);
  cout << "### ANS: " << endl;
  for(auto v:r2){
    for(auto vv:v)
      cout << vv << " ";
    cout << endl;
  }
  cout << endl << endl;
  
  auto r3 = combinationSum3(3,15);
  cout << "### ANS: " << endl;
  for(auto v:r3){
    for(auto vv:v)
      cout << vv << " ";
    cout << endl;
  }
  cout << endl << endl;
  // ANS: [[1,5,9],[1,6,8],[2,4,9],[2,5,8],[2,6,7],[3,4,8],[3,5,7],[4,5,6]]

  auto r5 = combinationSum3(5,15);
  cout << "### ANS: " << endl;
  for(auto v:r5){
    for(auto vv:v)
      cout << vv << " ";
    cout << endl;
  }

  auto r4 = combinationSum3(8,36);
  cout << "### ANS: " << endl;
  for(auto v:r4){
    for(auto vv:v)
      cout << vv << " ";
    cout << endl;
  }

  auto r6 = combinationSum3(9,45);
  cout << "### ANS: " << endl;
  for(auto v:r6){
    for(auto vv:v)
      cout << vv << " ";
    cout << endl;
  }

  return 0;
}
