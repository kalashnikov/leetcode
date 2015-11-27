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

void helper(vector<int>& nums, int lo, int hi, TreeNode* pre){
  if ( lo>hi ) return;
  int idx = lo + (hi-lo)/2;
  TreeNode *ptr = new TreeNode(nums[idx]); 
  if ( pre->val > ptr->val ) { 
    pre->left = ptr;
    //cout << idx << ":" << nums[idx] << " | left node." << endl;
  } else { 
    pre->right = ptr;
    //cout << idx << ":" << nums[idx] << " | right node." << endl;
  }
  helper(nums,lo,idx-1,ptr);
  helper(nums,idx+1,hi,ptr);
}

// 16 ms
TreeNode* sortedArrayToBST(vector<int>& nums) {
  if(nums.size()<1) return NULL; 
  int idx = nums.size()/2 + 0.5;
  TreeNode *head = new TreeNode(nums[idx]); 
  //cout << idx << ":" << nums[idx] << endl;
  helper(nums,0,idx-1,head);
  helper(nums,idx+1,nums.size()-1,head);
  return head;
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

int main(){

  vector<int> i1 { 1,2,3,4,5,6,7 };
  auto p1 = sortedArrayToBST(i1);

  TreeNode* ptr;
  list<TreeNode*> q{p1};
  while(!q.empty()){
    ptr = q.front(); q.pop_front();
    if(!ptr) continue;
    if(ptr->left)  cout << ptr->val << "  left: " <<  ptr->left->val << endl;
    if(ptr->right) cout << ptr->val << " right: " << ptr->right->val << endl;
    q.push_back(ptr->left);
    q.push_back(ptr->right);
  }
  cout << endl;
  
  auto a1 = preorderTraversal(p1);
  for(auto v:a1) cout << v << " "; cout << endl; 

  return 0;
}
