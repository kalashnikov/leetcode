#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void helper(vector<string>& ans, string cur, TreeNode* root){
  stringstream ss;
  if ( cur.length()!=0 ) ss << cur << "->";
  ss << root->val;
  if ( root->left == NULL && root->right == NULL ) { 
    ans.push_back(ss.str());
    return;
  }
  if (root->left)  helper(ans, ss.str(), root->left);
  if (root->right) helper(ans, ss.str(), root->right);
}

vector<string> binaryTreePaths(TreeNode* root) {
  vector<string> ans; 
  if ( root==NULL ) return ans; 
  helper(ans, "", root);
  return ans;
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
  TreeNode n9(9);

  n3.left = &n5;
  n3.right= &n1;
  n5.left = &n6;
  n5.right= &n2;
  n2.left = &n7;
  n2.right= &n4;
  n1.left = &n0;
  n1.right= &n8;
  n8.right= &n9;

  auto a1 = binaryTreePaths(&n3);
  for(auto v:a1) cout << v << endl; 
    
  return 0;
}
