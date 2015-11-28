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

int kthSmallest1(TreeNode* root, int k) {
  if(!root) return 0;
  vector<int> cache;
  TreeNode *ptr;
  list<TreeNode*> q { root };
  while(!q.empty()) {
    ptr = q.front(); q.pop_front();
    if(!ptr) continue;
    cache.push_back(ptr->val);    
    q.push_front(ptr->left);
    q.push_front(ptr->right);
  }
  sort(cache.begin(),cache.end());
  return cache[k-1];
}

// OJ will check tree and will Runtime Error 
// if early return using Morris Algorithm
int kthSmallest3(TreeNode* root, int k) {
  TreeNode* curNode = root;
  vector<int> nodes;
  while (curNode) {
    if (curNode->left) {
      TreeNode* predecessor = curNode->left;

      // Create backward linking 
      while (predecessor->right && predecessor->right != curNode)
        predecessor = predecessor->right;

      if (!(predecessor->right)) {
        predecessor->right = curNode;
        curNode = curNode->left;
      }
      else {
        predecessor->right = NULL;
        nodes.push_back(curNode->val);
        curNode = curNode->right;
      }
    }
    else {
      nodes.push_back(curNode->val);
      curNode = curNode->right;
    }
    for(auto v:nodes) cout << v << " "; cout << endl;
    if ( nodes.size()==k ) return nodes[k-1];
  }
  return 0; 
}

// Some bug existed
int kthSmallest2(TreeNode* root, int k) {
  if(!root) return 0;
  vector<int> cache; 

  TreeNode *ptr, *cur = root;
  while(cur) {
    ptr = cur;
    if ( ptr->left ) {
      ptr = ptr->left;
      while(ptr->right && ptr->right!=cur) ptr = ptr->right;
      ptr->right = cur;
    }
    if ( cur->left ) { 
      cur = cur->left;
    } else {
      ptr = cur->right;
      while( ptr && ptr->left && ptr->left==cur){
        cache.push_back(cur->val);
        cur->right = NULL;
        cur = ptr; // back to acestor
        ptr = cur->right;
      }
      cache.push_back(cur->val);
      cur = cur->right;
    }

    if ( cur == root ) { 
      cache.push_back(cur->val);
      cur = cur->right;
    }

    if ( cur ) cout << cur->val << " | ";
    for(auto v:cache) cout << v << " "; cout << endl;
    if(cache.size()>=k) return cache[k-1]; 
  }
  return cache.back(); 
}

// https://leetcode.com/discuss/43271/c-solution-using-in-order-traversal
void inorder(TreeNode* root, vector<int> &res){
  if(!root) return;
  inorder(root->left, res);
  res.push_back(root->val);
  inorder(root->right,res);

}
int kthSmallest(TreeNode* root, int k) {
  if(!root) return -1;
  vector<int> arr;
  inorder(root, arr);
  return arr[k-1];
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

  cout << kthSmallest(&n6,9) << endl;
  return 0;
}
