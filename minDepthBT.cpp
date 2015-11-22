#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int helper(int cur, TreeNode* root) {
  if ( root==NULL ) return cur;
  if(root->left ==NULL && root->right!=NULL ) return helper(cur+1,root->right); 
  if(root->left !=NULL && root->right==NULL ) return helper(cur+1,root->left); 
  return min(helper(cur+1,root->left),helper(cur+1,root->right));
}

int minDepth(TreeNode* root) {
  if(root==NULL) return 0;
  return helper(0,root);
}

// https://leetcode.com/discuss/20532/my-concise-c-solution
int minDepth(TreeNode *root) {
  if(!root) return 0;
  if(!root->left) return 1 + minDepth(root->right);
  if(!root->right) return 1 + minDepth(root->left);
  return 1+min(minDepth(root->left),minDepth(root->right));
}

//        _______3______
//       /              \
//    ___5__          ___1__
//   /      \        /      \
//   6      _2       0       8
//         /  \
//         7   4
//
int main(){

  TreeNode n6(6);
  TreeNode n0(0);
  TreeNode n2(2);
  TreeNode n3(3);
  TreeNode n4(4);
  TreeNode n5(5);
  TreeNode n7(7);
  TreeNode n8(8);
  TreeNode n1(1);
  TreeNode n9(9);

  //n3.left = &n5;
  n3.right= &n1;
  n5.left = &n6;
  n5.right= &n2;
  //n2.left = &n7;
  n2.right= &n4;
  //n1.left = &n0;
  //n1.right= &n8;
  //n8.right= &n9;

  cout << minDepth(&n3) << endl;
    
  return 0;
}
