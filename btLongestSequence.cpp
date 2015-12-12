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

// Top-down will fail because only know parent node value can determine to pass len+1 or 1 
// Try 1->2->2->3 
int longestConsecutive(TreeNode* root) {
  if(!root) return 0; 
  int rcnt = longestConsecutive(root->right);
  if ( root->right!=NULL && root->right->val==(root->val+1) )  rcnt++; 
  int lcnt = longestConsecutive(root->left);
  if ( root->left!=NULL && root->left->val==(root->val+1) )    lcnt++;
  int ans = max(1,max(rcnt,lcnt));
  cout << root->val << ": " << ans << endl;
  return ans; 
}

/*
 *  Good 2
int helper(TreeNode* root, int len, TreeNode* cur) {
  if(!cur) return len;
  if (cur->val == root->val+1) {  
    return max(helper(cur, len+1, cur->left), helper(cur, len+1, cur->right));
  } else {  
    // Important 
    return max(len, max(helper(cur, 1, cur->left), helper(cur, 1, cur->right))); 
  }
}

int longestConsecutive(TreeNode* root) {
  if(!root) return 0; 
  return max(helper(root, 1, root->left),helper(root, 1, root->right)); 
}
*/

/*
 *  Good 1
int helper(TreeNode* root, int len, TreeNode* cur) {
  if(!cur) return len;
  len = (root && cur->val == root->val+1) ? len+1 : 1;
  return max(len, max(helper(cur, len, cur->left), helper(cur, len, cur->right))); 
}

int longestConsecutive(TreeNode* root) {
  if(!root) return 0; 
  return helper(NULL, 0, root);
}
*/

//        _______5______
//       /              \
//    ___2__          ___1__
//   /      \        /      \
//   6      _3       0       8
//         /  \
//         7   4
//
int main(){

  TreeNode n0(0);
  TreeNode n1(1);
  TreeNode n2(2);
  TreeNode n3(2);
  TreeNode n4(3);
  TreeNode n5(1);
  TreeNode n6(6);
  TreeNode n7(7);
  TreeNode n8(8);
  //TreeNode n9(9);

  n5.left = &n2;
  //n5.right= &n1;
  //n2.left = &n6;
  n2.right= &n3;
  //n3.left = &n7;
  n3.right= &n4;
  n1.left = &n0;
  n1.right= &n8;
  //n0.right= &n9;

  cout << longestConsecutive(&n5) << " 2" << endl;

  return 0;
}
