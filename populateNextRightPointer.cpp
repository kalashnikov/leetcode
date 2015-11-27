#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

struct TreeLinkNode {
 int val;
 TreeLinkNode *left, *right, *next;
 TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

// https://leetcode.com/discuss/7327/a-simple-accepted-solution
void connect_while(TreeLinkNode *root) {
  if (root == NULL) return;
  TreeLinkNode *pre = root;
  TreeLinkNode *cur = NULL;
  while(pre->left) {
    cur = pre;
    while(cur) {
      cur->left->next = cur->right;
      if(cur->next) cur->right->next = cur->next->left;
      cur = cur->next;
    }
    pre = pre->left;
  }
}

void helper(TreeLinkNode* root, TreeLinkNode* aux){ 
  if(root->left==NULL || root->right==NULL) return;
  root->left->next = root->right;
  root->right->next = aux;
  //printf("%d next to %d\n", (root->left)?root->left->val:-1, (root->right)?root->right->val:-1);
  //printf("%d next to %d\n", (root->right)?root->right->val:-1, (aux)?aux->val:-1);
  helper(root->left,root->right->left);
  helper(root->right,((aux)?aux->left:NULL));
}

void connect(TreeLinkNode *root) {
  if(root==NULL) return;
  helper(root,NULL); 
}

//        _______3______
//       /              \
//    ___5__          ___1__
//   /      \        /      \
//  6        2       0       8
//
int main(){

  TreeLinkNode n6(6);
  TreeLinkNode n0(0);
  TreeLinkNode n2(2);
  TreeLinkNode n3(3);
  TreeLinkNode n5(5);
  TreeLinkNode n8(8);
  TreeLinkNode n1(1);

  n3.left = &n5;
  n3.right= &n1;
  n5.left = &n6;
  n5.right= &n2;
  n1.left = &n0;
  n1.right= &n8;

  connect(&n3);

  return 0;
}
