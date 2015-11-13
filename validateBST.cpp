#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool helper(TreeNode* stn, long minv, long maxv){
  if(!stn) return true;
  if(stn->val <= minv || stn->val >= maxv ) return false; 
  return ( helper(stn->left, minv, min((long)stn->val,maxv)) && 
           helper(stn->right,max((long)stn->val,minv), maxv) ); 
}

bool isValidBST(TreeNode* root) {
  if(!root) return true;
  return ( helper(root->left, LONG_MIN, root->val) && 
           helper(root->right,root->val, LONG_MAX) ); 
}

int main(){
  TreeNode root(10);
  TreeNode l(5);
  TreeNode r(15);
  TreeNode r1(6);
  TreeNode r2(20);
  root.left  = &l;
  root.right = &r;
  r.left = &r1;
  r.right= &r2;
  cout << isValidBST(&root) << endl; 

  return 0;
}
