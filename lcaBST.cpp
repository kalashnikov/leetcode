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

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if( root==NULL ) return NULL;
  if( p   ==NULL ) return    q;
  if( q   ==NULL ) return    p;
  if( p->val > q->val ) return lowestCommonAncestor(root, q, p);
  if( p->val <= root->val && q->val >= root->val ) return root;
  if( q->val <  root->val ) { 
    // p < q < root 
    root = root->left;
  } else {
    // root < p < q
    root = root->right;
  }
  return lowestCommonAncestor(root, p, q);
}

//        _______6______
//       /              \
//    ___2__          ___8__
//   /      \        /      \
//   0      _4       7       9
//         /  \
//         3   5
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
  TreeNode n9(9);

  n6.left = &n2;
  n6.right= &n8;
  n2.left = &n0;
  n2.right= &n4;
  n4.left = &n3;
  n4.right= &n5;
  n8.left = &n7;
  n8.right= &n9;

  cout << lowestCommonAncestor(&n6,&n2,&n4)->val << endl;
  cout << lowestCommonAncestor(&n6,&n2,&n8)->val << endl;

  return 0;
}
