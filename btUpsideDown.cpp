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

TreeNode* upsideDownBinaryTree(TreeNode* root) {
  if(!root) return NULL;

  TreeNode *ptr = root, *ans;
  vector<TreeNode*> vec;
  while(ptr){

    while(ptr->left) { 
      vec.push_back(ptr);
      cout << "Push: " << ptr->val << endl; 
      ptr = ptr->left;
    }

    while(!vec.empty()){
      ptr->right = vec.back();
      ptr->left  = vec.back()->right;
      ptr = vec.back(); 
      vec.pop_back();
    }

    cout << " ptr to " << ptr->left->val << endl;
    ptr = ptr->left;
  }
  return NULL;
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

  upsideDownBinaryTree(&n3);

  TreeNode* ptr;
  list<TreeNode*> q{&n3};
  while(!q.empty()){
    ptr = q.front(); q.pop_front();
    if(ptr==NULL) continue;
    if(ptr->left)  printf("%d left: %d\n", ptr->val, ptr->left->val);
    if(ptr->right) printf("%d right: %d\n", ptr->val, ptr->right->val);
    q.push_back(ptr->left);
    q.push_back(ptr->right);
  }
  cout << endl;

  return 0;
}
