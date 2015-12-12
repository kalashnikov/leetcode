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

// https://leetcode.com/discuss/34569/very-simple-straight-based-math-catalan-number-times-space
int numTrees2(int n) {
    long long ans=1,i;
    for(i=1;i<=n;i++)
        ans = ans*(i+n)/i;
    return ans/i;
}

// https://www.wikiwand.com/en/Catalan_number
int numTrees(int n) {
  static unordered_map<int, long> ans;
  ans[0] = 1; ans[1] = 1; ans[2] = 2;
  if(n<3||ans.count(n)) return ans[n]; 
  int i = 3; 
  while(i<=n){
    ans[i] = (4*i-2)*ans[i-1]/(i+1);
    i++;
  }
  return ans[n];
}

// https://leetcode.com/discuss/26330/30-ms-c-solution
vector<TreeNode *> generateTrees2(int n) {
  if(n==0) return vector<TreeNode*>();
  return helper(1,n);
}
vector<TreeNode*> helper(int s, int e) {
  if (s > e) {
    return vector<TreeNode*>(1,NULL);
  }
  vector<TreeNode*> result;
  for (int i=s; i <= e; ++i) {
    vector<TreeNode*> left, right;
    left = helper(s,i-1);
    right = helper(i+1,e);
    for (int j = 0; j < left.size(); ++j) {
      for (int k = 0; k < right.size(); ++k) {
        TreeNode* root = new TreeNode(i);
        root->left = left[j];
        root->right = right[k];
        result.push_back(root);
      }
    }
  }

  return result;
}
//==================================================//

TreeNode* copyTree(TreeNode* source){
  if(!source) return NULL;
  TreeNode* target = new TreeNode(source->val);
  target->left  = copyTree(source->left);
  target->right = copyTree(source->right);
  return target;
}

vector<TreeNode*> generateTrees(int n) {
 
  vector<TreeNode*> ans, tmp; 
  if(n==0) return ans;
  
  TreeNode *ptr, *aux, *newT;
  ptr = new TreeNode(1);
  ans.push_back(ptr); 
  if(n==1) return ans;

  int i = 2;
  while(i<=n){
    tmp.clear();

    for(auto v:ans){
      aux = v;

      int j = 0;
      while(aux && aux->right) {
       
        // Copy and go to same position node 
        int k = j;
        newT = copyTree(v);
        tmp.push_back(newT);
        while(k--) newT = newT->right;

        // Insert new node into this position
        ptr = newT->right; 
        newT->right = new TreeNode(i); 
        newT->right->left = ptr;

        aux = aux->right;
        j++;
      }

      // Right most insertion 
      aux = copyTree(v);
      tmp.push_back(aux);
      while(aux && aux->right) aux = aux->right; 
      aux->right = new TreeNode(i);
  
      // Insert new node as new root 
      aux = copyTree(v);
      ptr = new TreeNode(i);
      ptr->left = aux;
      tmp.push_back(ptr);
    }

    swap(ans, tmp);
    i++;
  }

  return ans;
}

int main(){
  //cout << numTrees(1) << "   1" << endl;
  //cout << numTrees(2) << "   2" << endl;
  //cout << numTrees(3) << "   5" << endl;
  //cout << numTrees(4) << "  14" << endl;
  //cout << numTrees(5) << "  42" << endl;
  //cout << numTrees(6) << " 132" << endl;
  //cout << numTrees(19) << " 1767263190" << endl;

  auto a1 = generateTrees(1);
  cout << "Gen1: " << endl;
  for(auto v:a1) {
    TreeNode* ptr;
    list<TreeNode*> q {v};
    while(!q.empty()){
      ptr = q.front(); q.pop_front();
      if(!ptr) continue;
      cout << ptr->val << endl;
      if(ptr->left  ) { 
        cout << ptr->val << "  left: " << ptr->left->val << endl;
        q.push_back(ptr->left);
      }
      if(ptr->right ) {
        cout << ptr->val << " right: " << ptr->right->val << endl;
        q.push_back(ptr->right);
      }
    }
  }

  auto a2 = generateTrees(2); 
  cout << "Gen2: " << endl;
  for(auto v:a2) {
    TreeNode* ptr;
    list<TreeNode*> q {v};
    while(!q.empty()){
      ptr = q.front(); q.pop_front();
      if(!ptr) continue;
      if(ptr->left  ) { 
        cout << ptr->val << "  left: " << ptr->left->val << endl;
        q.push_back(ptr->left);
      }
      if(ptr->right ) {
        cout << ptr->val << " right: " << ptr->right->val << endl;
        q.push_back(ptr->right);
      }
    }
  }
  
  auto a3 = generateTrees(3); 
  cout << "Gen3: " << endl;
  int i = 1;
  for(auto v:a3) {
    cout << " ### " << i++ << " ### " << endl;
    TreeNode* ptr;
    list<TreeNode*> q {v};
    while(!q.empty()){
      ptr = q.front(); q.pop_front();
      if(!ptr) continue;
      if(ptr->left  ) { 
        cout << ptr->val << "  left: " << ptr->left->val << endl;
        q.push_back(ptr->left);
      }
      if(ptr->right ) {
        cout << ptr->val << " right: " << ptr->right->val << endl;
        q.push_back(ptr->right);
      }
    }
  }
 
  auto a4 = generateTrees(4); 
  cout << "Gen4: " << endl;
  i = 1;
  for(auto v:a4) {
    cout << " ### " << i++ << " ### " << endl;
    TreeNode* ptr;
    list<TreeNode*> q {v};
    while(!q.empty()){
      ptr = q.front(); q.pop_front();
      if(!ptr) continue;
      if(ptr->left  ) { 
        cout << ptr->val << "  left: " << ptr->left->val << endl;
        q.push_back(ptr->left);
      }
      if(ptr->right ) {
        cout << ptr->val << " right: " << ptr->right->val << endl;
        q.push_back(ptr->right);
      }
    }
  }
  return 0;
}
