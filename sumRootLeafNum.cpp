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

void helper(int& ans, int& cur, TreeNode* root) {
  if(!root) return;
  if(!root->right && !root->left){
    ans += cur*10 + root->val;
    return ;
  }
  cur = cur*10 + root->val;
  helper(ans, cur, root->left );
  helper(ans, cur, root->right);
  cur /= 10;
}

int sumNumbers(TreeNode* root) {
  if(!root) return 0;
  int ans = 0, cur = 0; 
  helper(ans, cur, root);
  return ans;
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

  n3.left = &n5;
  n3.right= &n1;
  n5.left = &n6;
  n5.right= &n2;
  n2.left = &n7;
  n2.right= &n4;
  n1.left = &n0;
  n1.right= &n8;

  cout << sumNumbers(&n3) << endl;

  return 0;
}
