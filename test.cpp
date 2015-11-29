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

// Morris Algorithm: O(n)/O(1)
vector<int> inorder(TreeNode* root) { 
  vector<int> ans;
  if(!root) return ans;

  TreeNode *ptr = root, *pre;
  while(ptr){
    if(ptr->left){
      pre = ptr->left;
      
      // Find the right-most node;
      while( pre->right && pre->right!=ptr )
        pre = pre->right; 

      if(!(pre->right)) {
        // 1. If this node have no right node, create back-link 
        pre->right = ptr; 
        ptr = ptr->left;
      } else {
        // 3. Recover the back-link
        pre->right = NULL;
        ans.push_back(ptr->val);
        ptr = ptr->right; 
      }
    } else {
      // 2. Use the back-link 
      ans.push_back(ptr->val);
      ptr = ptr->right; 
    }
  }

  return ans;
}

void inorderRecur(TreeNode* root){
  if(!root) return;
  inorderRecur(root->left);
  cout << root->val << " ";
  inorderRecur(root->right);
}

void preorder(TreeNode* root){
  if(!root) return;
  cout << root->val << " ";
  preorder(root->left);
  preorder(root->right);
}

void postorder(TreeNode* root){
  if(!root) return;
  postorder(root->left);
  postorder(root->right);
  cout << root->val << " ";
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
  n4.left = &n3;
  n4.right= &n5;
  n2.right= &n4;
  n8.left = &n7;
  n8.right= &n9;

  auto a = inorder(&n6);
  for(auto v:a) cout << v << " "; cout << endl;

  preorder(&n6);
  cout << endl;
  
  inorderRecur(&n6);
  cout << endl;
  
  postorder(&n6);
  cout << endl;
  return 0;
}
