#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <cmath>

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int countNodes(TreeNode* root) {
  if ( root==NULL) return 0;
  if ( root->left==NULL && root->right==NULL ) return 1;

  list<TreeNode*> lt;
  lt.push_back(root);

  int cnt = 0;
  TreeNode* ptr;
  while(!lt.empty()){
    ptr = lt.front(); lt.pop_front();
    cnt++; 

    if(ptr->right) { 
      lt.push_back(ptr->left);
      lt.push_back(ptr->right);
    } else if ( ptr->left ) {
      cnt++; 
    }
  }

  return cnt;
}

int countNodes1(TreeNode* root) {
  if ( root==NULL) return 0;
  if ( root->left==NULL && root->right==NULL ) return 1;

  TreeNode* ptr;
  int lh = 1, rh = 1;
  ptr=root; while((ptr=ptr->left)!=NULL)  lh++;
  ptr=root; while((ptr=ptr->right)!=NULL) rh++;
  if ( lh==rh ) return ((1<<lh)-1);
  return countNodes1(root->left)+countNodes1(root->right)+1;
}

int main(){
  TreeNode root(1); 
  TreeNode l(2); 
  root.left = &l;
  TreeNode r(3); 
  root.right = &r;
  TreeNode l4(4); 
  l.left = &l4;
  cout << countNodes1(&root) << endl;
  return 0;
}
