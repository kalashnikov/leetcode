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

vector<vector<int>> levelOrder(TreeNode* root) {
  vector<vector<int>> ans;
  if ( root==NULL ) return ans;

  TreeNode* ptr;
  vector<int> vc;
  list<TreeNode*> level, child;
  
  level.push_back(root);

  while(level.size()!=0){
    ptr = level.front(); level.pop_front();
    vc.push_back(ptr->val);
    if(ptr->left)  child.push_back(ptr->left);
    if(ptr->right) child.push_back(ptr->right);

    if(level.size()==0){
      ans.push_back(vc);
      vc.clear();
      swap(level, child);
    }
  }

  return ans; 
}

vector<vector<int>> levelOrderBottom(TreeNode* root) {
  vector<vector<int>> ans;
  if ( root==NULL ) return ans;

  TreeNode* ptr;
  vector<int> vc;
  list<TreeNode*> level, child;
  
  level.push_back(root);

  while(level.size()!=0){
    ptr = level.front(); level.pop_front();
    vc.push_back(ptr->val);
    if(ptr->left)  child.push_back(ptr->left);
    if(ptr->right) child.push_back(ptr->right);

    if(level.size()==0){
      ans.push_back(vc);
      vc.clear();
      swap(level, child);
    }
  }

  reverse(ans.begin(),ans.end());
  return ans; 
}

//    3
//   / \
//  9  20
//    /  \
//   15   7
int main(){
  TreeNode n3(3);
  TreeNode n9(9);
  TreeNode n20(20);
  TreeNode n15(15);
  TreeNode n7(7);
  n3.left  = &n9;
  n3.right = &n20;
  n20.left  = &n15;
  n20.right = &n7;

  auto a = levelOrderBottom(&n3);
  for(auto v:a){
    for(auto vv:v){
      cout << vv << " ";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}
