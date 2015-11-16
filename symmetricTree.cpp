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

bool isSymmetric(TreeNode* root) {
  if ( root==NULL ) return true;

  TreeNode *ptr;
  vector<int> l1, l2;
  list<TreeNode*> t;

  t.push_back(root);
  while(t.size()){
    ptr = t.front(); t.pop_front();
    if(ptr==NULL) {
      l1.push_back(INT_MIN);
      continue;
    } 
    l1.push_back(ptr->val);
    t.push_back(ptr->left);
    t.push_back(ptr->right);
  }

  int idx = 0;
  t.push_back(root);
  while(t.size()){
    ptr = t.front(); t.pop_front();
    if(ptr==NULL) {
      if(l1[idx++]!=INT_MIN) return false;
      l2.push_back(INT_MIN);
      continue;
    } 
    if(l1[idx++]!=ptr->val) return false;
    l2.push_back(ptr->val);
    t.push_back(ptr->right);
    t.push_back(ptr->left);
  }
  return true;
}

// https://leetcode.com/discuss/26705/15-lines-of-c-solution-8-ms
bool isSymmetric(TreeNode *root) {
  if (!root) return true;
  return helper(root->left, root->right);
}

bool helper(TreeNode* p, TreeNode* q) {
  if (!p && !q) {
    return true;
  } else if (!p || !q) {
    return false;
  }

  if (p->val != q->val) {
    return false;
  }

  return helper(p->left,q->right) && helper(p->right, q->left); 
}

//        _______3______
//       /              \
//    ___5__          ___1__
//   /      \        /      \
//  6        2       0       8
//
int main(){

  TreeNode n6(6);
  TreeNode n0(0);
  TreeNode n2(0);
  TreeNode n3(3);
  TreeNode n5(1);
  TreeNode n8(6);
  TreeNode n1(1);

  //n3.left = &n5;
  n3.right= &n1;
  n5.left = &n6;
  n5.right= &n2;
  n1.left = &n0;
  n1.right= &n8;

  cout << isSymmetric(&n3) << endl;
  return 0;
}
