#include <iostream>
#include <vector>
#include <set>
#include <list>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> postorderTraversal(TreeNode* root) {
  TreeNode* ptr; 
  set<TreeNode*> visited;
  vector<int> ans;
  list<TreeNode*> q{root};
  while( !q.empty() ) {
    ptr = q.front(); q.pop_front(); 
    if(ptr==NULL) continue; 
    
    if((ptr->left==NULL  || visited.count(ptr->left )) && 
       (ptr->right==NULL || visited.count(ptr->right)) ){
      ans.push_back(ptr->val);
      visited.insert(ptr);
    } else { 
      q.push_front(ptr);
      q.push_front(ptr->right);
      q.push_front(ptr->left);
    }
  }
  return ans;
}

// Morris algorithm 
// O(n) time, O(1) space
// https://leetcode.com/discuss/36713/solutions-iterative-recursive-traversal-different-solutions
// Ref: http://www.cnblogs.com/AnnieKim/archive/2013/06/15/morristraversal.html
vector<int> inorderTraversal(TreeNode* root) {
  TreeNode* curNode = root;
  vector<int> nodes;
  while (curNode) {
    if (curNode -> left) {
      TreeNode* predecessor = curNode -> left;

      // Create backward linking 
      while (predecessor -> right && predecessor -> right != curNode)
        predecessor = predecessor -> right;

      if (!(predecessor -> right)) {
        predecessor -> right = curNode;
        curNode = curNode -> left;
      }
      else {
        predecessor -> right = NULL;
        nodes.push_back(curNode -> val);
        curNode = curNode -> right;
      }
    }
    else {
      nodes.push_back(curNode -> val);
      curNode = curNode -> right;
    }
  }
  return nodes;
}

vector<int> inorderTraversal2(TreeNode* root) {
  TreeNode* ptr; 
  set<TreeNode*> visited;
  vector<int> ans;
  list<TreeNode*> q{root};
  while( !q.empty() ) {
    ptr = q.front(); q.pop_front(); 
    if(ptr==NULL) continue; 
    
    if(ptr->left==NULL  || visited.count(ptr->left )){
      ans.push_back(ptr->val);
      visited.insert(ptr);
      q.push_front(ptr->right);
    } else { 
      q.push_front(ptr);
      q.push_front(ptr->left);
    }
  }
  return ans;
}

vector<int> preorderTraversal(TreeNode* root) {
  TreeNode* ptr; 
  vector<int> ans;
  list<TreeNode*> q { root };
  while( !q.empty() ) {
    ptr = q.front(); q.pop_front();
    if(ptr==NULL) continue;
    ans.push_back(ptr->val);
    q.push_front(ptr->right);
    q.push_front(ptr->left);
  }
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
 
  /*
  TreeNode n6(6);
  TreeNode n0(0);
  TreeNode n2(2);
  TreeNode n3(3);
  TreeNode n4(4);
  TreeNode n5(5);
  TreeNode n7(7);
  TreeNode n8(8);
  TreeNode n1(1);
  */

  n3.left = &n5;
  n3.right= &n1;
  n5.left = &n6;
  n5.right= &n2;
  n2.left = &n7;
  n2.right= &n4;
  n1.left = &n0;
  n1.right= &n8;

  auto a1 = preorderTraversal(&n3);
  for(auto v:a1) cout << v << " "; cout << endl; 

  auto a2 = inorderTraversal(&n3);
  for(auto v:a2) cout << v << " "; cout << endl; 

  auto a3 = postorderTraversal(&n3);
  for(auto v:a3) cout << v << " "; cout << endl; 
  return 0;
}
