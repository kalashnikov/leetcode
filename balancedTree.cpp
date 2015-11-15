#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 16ms - Not good.
int getMaxDepth(TreeNode* root, int cur_level){
  if(root==NULL) return cur_level;
  return max(getMaxDepth(root->left,cur_level+1), getMaxDepth(root->right,cur_level+1));
}

bool helper(TreeNode* root, int cur_level){
  if (root==NULL) return true;
  if ((abs(getMaxDepth(root->left,cur_level+1)-getMaxDepth(root->right,cur_level+1))>1)) return false;
  return helper(root->left, cur_level+1) && helper(root->right, cur_level+1); 
}

bool isBalanced1(TreeNode* root) {
  if(root==NULL) return true;
  return helper(root,0); 
}

// https://leetcode.com/discuss/22898/the-bottom-up-o-n-solution-would-be-better
// Top-down 
// 16ms | Not good.
int depth (TreeNode *root) {
  if (root == NULL) return 0;
  return max (depth(root -> left), depth (root -> right)) + 1;
}

bool isBalanced (TreeNode *root) {
  if (root == NULL) return true;

  int left=depth(root->left);
  int right=depth(root->right);

  return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

// Bottom Up
// 12ms | Good.
int dfsHeight (TreeNode *root) {
  if (root == NULL) return 0;

  int leftHeight = dfsHeight (root -> left);
  if (leftHeight == -1) return -1;
  int rightHeight = dfsHeight (root -> right);
  if (rightHeight == -1) return -1;

  if (abs(leftHeight - rightHeight) > 1)  return -1;
  return max (leftHeight, rightHeight) + 1;
}
bool isBalanced(TreeNode *root) {
  return dfsHeight (root) != -1;
}

//           _______3______
//          /              \
//       ___5__          ___1__
//      /      \        /      \
//     6       2       0       8
//    /  \                    / 
//   7    4                  10
//  /                       /
// 9                       11
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
  TreeNode n10(10);
  TreeNode n11(11);

  //n3.left = &n5;
  //n3.right= &n1;
  n5.left = &n6;
  n5.right= &n2;
  n6.left = &n7;
  n6.right= &n4;
  n1.left = &n0;
  n1.right= &n8;
  n7.left = &n9;
  //n8.left = &n10;
  //n10.left = &n11;

  cout << isBalanced(&n3) << endl; 

  return 0;
}
