#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void helper(vector<vector<int>>& ans, vector<int>& cur, TreeNode* root, int sum){
  if ( root==NULL ) return;
  cur.push_back(root->val);
  if ( root->left == NULL && root->right == NULL && sum==root->val) {
    ans.push_back(cur);
  }
  helper(ans, cur, root->left,  sum - root->val);
  helper(ans, cur, root->right, sum - root->val);
  cur.pop_back(); 
}

vector<vector<int>> pathSum(TreeNode* root, int sum) {
  vector<int> cur; 
  vector<vector<int>> ans; 
  if ( root==NULL ) return ans; 
  helper(ans, cur, root, sum);
  return ans;
}

bool helper(int cur, TreeNode* root, int& sum){
  if ( root==NULL ) return false;
  cur += root->val;
  if ( root->left == NULL && root->right == NULL && cur == sum ) {
    return true;
  }
  return (helper(cur, root->left, sum) || helper(cur, root->right, sum)); 
}

bool hasPathSum(TreeNode* root, int sum) {
  if ( root==NULL ) return false; 
  if ( helper(0, root, sum) ) return true;
  return false;
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
  
  cout << hasPathSum(&n3, 15) << endl;

  auto a1 = pathSum(&n3, 14);
  for(auto v:a1){ 
    for(auto vv:v){
      cout << vv << " ";
    }
    cout << endl; 
  }
  cout << endl; 
    
  return 0;
}
