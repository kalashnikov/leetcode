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

// Iterative version
TreeNode* upsideDownBinaryTree(TreeNode* root) {
  if(!root) return root;
  TreeNode *ptr = root, *aux; 
  vector<TreeNode*> l;
  while(ptr){
    l.push_back(ptr);
    ptr = ptr->left;
  }

  for(int i=l.size()-1;i>0;i--){
    ptr = l[i]; 
    aux = l[i-1]; 
    if(aux) ptr->left  = aux->right; 
    ptr->right = aux; 

    if(ptr->left)  ptr->left->left = ptr->left->right = NULL;
    if(ptr->right) ptr->right->left = ptr->right->right = NULL;
  }

  return l.back();
}

// Recursive version 
// https://leetcode.com/discuss/52414/c-recursive-solution-easy-understanding
TreeNode* upsideDownBinaryTree(TreeNode* root) {
  if (!root || !root->left) return root;
  TreeNode* cur_left = root->left;
  TreeNode* cur_right = root->right;
  TreeNode* new_root = upsideDownBinaryTree(root->left);
  cur_left->right = root;
  cur_left->left = cur_right;
  root->left = nullptr;
  root->right = nullptr;
  return new_root;
}

//        _______1______
//       /              \
//    ___2__             3
//   /      \
//   4       5
//
int main(){

  TreeNode n1(1);
  TreeNode n2(2);
  TreeNode n3(3);
  TreeNode n4(4);
  TreeNode n5(5);

  n1.left = &n2;
  //n1.right= &n3;
  //n2.left = &n4;
  //n2.right= &n5;

  auto ptr = upsideDownBinaryTree(&n1);
  list<TreeNode*> l{ptr};
  while(l.size()){
    ptr = l.front();l.pop_front();
    if(!ptr) continue;
    cout << ptr->val << " ";
    l.push_back(ptr->left);
    l.push_back(ptr->right);
  }
  cout << endl;
  return 0;
}
