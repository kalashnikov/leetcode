#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

// https://leetcode.com/discuss/52060/72ms-c-solution-using-one-stack-o-n-time-and-space
bool verifyPreorder(vector<int>& preorder){
    // using stack
    int sz = preorder.size();
    if(sz < 2) return true;
    stack<int> s;
    s.push(preorder[0]);
    int curr_p = INT_MIN;
    for(int i=1; i<sz; i++){ 
        if(s.empty() || preorder[i]<s.top()){ // if current node is less than stack top, then go to left subtree
            if(preorder[i]<curr_p) return false; 
            s.push(preorder[i]);
        }
        else{
            while(!s.empty() && s.top()<preorder[i]){ //find curr_p such that current node is right child of curr_p
                curr_p = s.top();
                s.pop();
            }
            s.push(preorder[i]);
        }
    }
    return true;
}

bool helper(vector<int>& preorder, int lo, int hi){
  if(lo>=hi) return true;
  int root = preorder[lo]; 
  //int lim  = (hi-lo+1)/2+0.5; // ceil
  int idx = lo+1, less = 0, more = 0;
  //cout << lo << " " << hi << " | " << lim << endl;
  while(idx<=hi && preorder[idx]<root){ idx++; less++; }
  //cout << less << " " << lim << endl;
  //if ( less > lim ) return false;
  while(idx<=hi && preorder[idx]>root){ idx++; more++; }
  if ( idx<hi ) return false;
  //if ( more > lim ) return false;
  //cout << more << " " << lim << endl;
  return helper(preorder,lo+1,lo+less) && helper(preorder,lo+less+1,hi); 
}

bool verifyPreorder_notgood(vector<int>& preorder) {
  if(preorder.size()<2) return true;
  return helper(preorder,0,preorder.size()-1);
}

int main(){
  vector<int> i1 { 5,2,1,3,4,6,8 };
  cout << verifyPreorder(i1) << " 1" << endl;
  return 0;
}
