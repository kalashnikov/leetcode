#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
  if( !p && !q ) return true;
  if( (!p && q ) || (p && !q) || (p && q && p->val!=q->val) ) return false;
  return isSameTree(p->left,q->left) && isSameTree(p->right, q->right);
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
  n3.left = &n5;
  n3.right= &n1;
  n5.left = &n6;
  n5.right= &n2;
  n2.left = &n7;
  n2.right= &n4;
  n1.left = &n0;
  n1.right= &n8;
  n8.right= &n9;

  TreeNode n6_(6);
  TreeNode n0_(0);
  TreeNode n2_(2);
  TreeNode n3_(3);
  TreeNode n4_(4);
  TreeNode n5_(5);
  TreeNode n7_(7);
  TreeNode n8_(8);
  TreeNode n1_(1);
  TreeNode n9_(9);
  n3_.left = &n5_;
  n3_.right= &n1_;
  n5_.left = &n6_;
  n5_.right= &n2_;
  n2_.left = &n7_;
  n2_.right= &n4_;
  n1_.left = &n0_;
  n1_.right= &n8_;
  n8_.right= &n9_;

  cout << isSameTree(&n3,&n3_) << endl;
    
  return 0;
}
