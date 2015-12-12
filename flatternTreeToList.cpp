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

// https://leetcode.com/discuss/36732/8ms-non-recursive-no-stack-c-solution
void flatten(TreeNode *root) {
  while (root) {
    if (root->left && root->right) {
      TreeNode* t = root->left;
      while (t->right)
        t = t->right;
      t->right = root->right;
    }

    if(root->left)
      root->right = root->left;
    root->left = NULL;
    root = root->right;
  }
}

void flatten(TreeNode* root) {
  if(!root) return;
  TreeNode *ptr, *head = root; 
  list<TreeNode*> l { root->left, root->right };
  root->left = root->right = NULL;
  while(!l.empty()){
    ptr = l.front(); l.pop_front();
    if(!ptr) continue;
    head->right = ptr; 
    head = ptr; 
    l.push_front(ptr->right);
    l.push_front(ptr->left);
    ptr->left = ptr->right = NULL;
  }
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

  flatten(&n3); 

  TreeNode *ptr = &n3;
  while(ptr){
    cout << ptr->val << " ";
    ptr = ptr->right; 
  }
  cout << endl;
  return 0;
}
