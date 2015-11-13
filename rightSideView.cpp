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

vector<int> rightSideView2(TreeNode* root) {
  vector<int> ans;
  if ( root==NULL ) return ans;
  list<TreeNode*> q, l;
  q.push_back(root);
  ans.push_back(root->val);
  
  TreeNode *ptr;
  while(!q.empty()){
    ptr = q.front(); q.pop_front();
    if(ptr->right!=NULL) l.push_back(ptr->right);
    if( ptr->left!=NULL) l.push_back(ptr->left);
    if(q.empty()){
      if(!l.empty()) ans.push_back(l.front()->val);
      swap(q,l);
    }
  }
  return ans; 
}

// https://leetcode.com/discuss/30455/my-c-solution-modified-preorder-traversal
void recursion(TreeNode *root, int level, vector<int> &res)
{
  if(root==NULL) return ;
  if(res.size()<level) res.push_back(root->val); // Key!!!
  recursion(root->right, level+1, res);
  recursion(root->left, level+1, res);
}

vector<int> rightSideView(TreeNode *root) {
  vector<int> res;
  recursion(root, 1, res);
  return res;
}

//     3
//    / \
//   9  20
//  /  
// 15   
int main(){
  TreeNode n3(3);
  TreeNode n9(9);
  TreeNode n20(20);
  TreeNode n15(15);
  n3.left  = &n9;
  n3.right = &n20;
  n9.left  = &n15;

  auto a = rightSideView(&n3);
  for(auto v:a){
    cout << v << " ";
  }
  cout << endl;

  return 0;
}
