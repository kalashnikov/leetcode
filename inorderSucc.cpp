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

TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
  if(!root) return root;

  list<TreeNode*> s;  
  while(root){
    if(root==p) {
      if(root->right==NULL) {
        if ( s.empty() ) {
          return NULL;
        } else if ( s.back()->right != root ) {
          return s.back();
        } else {
          while(s.size()!=1) s.pop_back();
          return s.back();
        }
      } else {
        root = root->right;
        while(root->left) root = root->left;
        return root;
      }
    } else if ( root->val > p->val ) {
      s.push_back(root);
      root = root->left;
    } else { 
      root = root->right;
    }
  }
  return NULL;
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

  cout <<  inorderSuccessor(&n6, &n0)->val   << " 2" << endl;
  cout <<  inorderSuccessor(&n6, &n3)->val   << " 4" << endl;
  cout <<  inorderSuccessor(&n6, &n2)->val   << " 3" << endl;
  cout <<  inorderSuccessor(&n6, &n5)->val   << " 6" << endl;
  cout <<  inorderSuccessor(&n6, &n8)->val   << " 9" << endl;
  cout <<  inorderSuccessor(&n6, &n4)->val   << " 5" << endl;
  cout <<  inorderSuccessor(&n6, &n6)->val   << " 7" << endl;
  cout << (inorderSuccessor(&n6, &n9)==NULL) << " 1" << endl;

  return 0;
}
