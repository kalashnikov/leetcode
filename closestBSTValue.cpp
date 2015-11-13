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

// 12ms 
int closestValue(TreeNode* root, double target) {
  int closest = root->val;
  while (root) {
    if (abs(closest - target) >= abs(root->val - target))
      closest = root->val;
    root = target < root->val ? root->left : root->right;
  }
  return closest;
}

// 16ms
// https://leetcode.com/discuss/54438/4-7-lines-recursive-iterative-ruby-c-java-python
int closestValue(TreeNode* root, double target) {
  if(root==NULL) return 0;

  TreeNode *ptr;
  int ans = INT_MAX; 
  double dif = LONG_MAX;
  list<TreeNode*> q { root };
  
  // BFS
  while(!q.empty()){
    ptr = q.front(); q.pop_front();
    if( abs(ptr->val-target) < dif ) {
      ans = ptr->val; 
      dif = abs(ptr->val - target);
    }
    if ( ptr->left!=NULL  ) q.push_back(ptr->left);
    if ( ptr->right!=NULL ) q.push_back(ptr->right);
  }
  return ans;
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

  cout << closestValue(&n6, 7.6) << endl;
  cout << closestValue(&n6, 3.2) << endl;
  cout << closestValue(&n6, 4.2) << endl;
  cout << closestValue(&n6, 5.6) << endl;
  cout << closestValue(&n0, INT_MAX) << endl;
  return 0;
}
