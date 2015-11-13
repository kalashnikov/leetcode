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

bool findNode(TreeNode* root, int target){
  bool found = false;
  TreeNode *ptr;
  list<TreeNode*> q;
  q.push_back(root);
  while(!q.empty()){
    ptr = q.front(); 
    q.pop_front();
    if( ptr->val == target ) return true; 
    if( ptr->left  ) q.push_back(ptr->left);
    if( ptr->right ) q.push_back(ptr->right);
  }
  return false;
}

// Binary Tree
TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
  if( root==NULL ) return NULL;
  if( p   ==NULL ) return    q;
  if( q   ==NULL ) return    p;

  // value: level 
  TreeNode *ptr;
  list<TreeNode*> l;
  unordered_map<TreeNode*, pair<int,TreeNode*>> leftmap; 
  unordered_map<TreeNode*, pair<int,TreeNode*>> rightmap; 

  if ( root->left ) { 
    l.push_back(root->left);
    leftmap[root->left] = { 1, root }; 
    while(!l.empty()){
      ptr = l.front(); 
      l.pop_front();
      if( ptr->left  ) { 
        l.push_back(ptr->left);
        leftmap[ptr->left]  = { leftmap[ptr].first + 1, ptr }; 
      }
      if( ptr->right ) { 
        l.push_back(ptr->right);
        leftmap[ptr->right] = { leftmap[ptr].first + 1, ptr }; 
      }
    }
  }

  auto p_left = leftmap.find(p);
  auto q_left = leftmap.find(q);
  if ( p_left!=leftmap.end() && 
       q_left!=leftmap.end() ) {
    if ( p_left->second.first == q_left->second.first ) {
      return p_left->second.second;
    } else if ( p_left->second.first < q_left->second.first ) {
      ptr = p;
      while(!findNode(ptr, q->val)) { 
        ptr = leftmap[ptr].second; // Try Ancestor
      }
      return ptr;
    } else { 
      ptr = q;
      while(!findNode(ptr, p->val)) { 
        ptr = leftmap[ptr].second; // Try Ancestor
      }
      return ptr;
    }
  }

  if ( p_left!=leftmap.end() || q_left!=leftmap.end() ) return root; 

  if ( root->right ) { 
    l.push_back(root->right);
    rightmap[root->right] = { 1, root }; 
    while(!l.empty()){
      ptr = l.front(); 
      l.pop_front();
      if( ptr->left  ) { 
        l.push_back(ptr->left);
        rightmap[ptr->left]  = { rightmap[ptr].first + 1, ptr }; 
      }
      if( ptr->right ) { 
        l.push_back(ptr->right);
        rightmap[ptr->right] = { rightmap[ptr].first + 1, ptr }; 
      }
    }
  }

  auto p_right = rightmap.find(p);
  auto q_right = rightmap.find(q);
  if ( p_right!=rightmap.end() && 
       q_right!=rightmap.end() ) {
    if ( p_right->second.first == q_right->second.first ) {
      return p_right->second.second;
    } else if ( p_right->second.first < q_right->second.first ) {
      ptr = p;
      while(!findNode(ptr, q->val)) { 
        ptr = rightmap[ptr].second; // Try Ancestor
      }
      return ptr;
    } else { 
      ptr = q;
      while(!findNode(ptr, p->val)) { 
        ptr = rightmap[ptr].second; // Try Ancestor
      }
      return ptr;
    }
  }

  return root;
}

TreeNode* lowestCommonAncestor1(TreeNode* root, TreeNode* p, TreeNode* q) {
  if( root==NULL ) return NULL;
  if( p   ==NULL ) return    q;
  if( q   ==NULL ) return    p;

  bool debug = false;

  // value: level 
  TreeNode *ptr;
  list<TreeNode*> l;
  unordered_map<TreeNode*, pair<int,TreeNode*>> db; 
  
  l.push_back(root);
  db[root] = { 0, root };
  if ( debug ) cout << "### Add: " << root->val << " 0" << endl;
  while(!l.empty()){
    ptr = l.front(); 
    l.pop_front();
    if( ptr->left  ) { 
      l.push_back(ptr->left);
      db[ptr->left]  = { db[ptr].first + 1, ptr }; 
      if ( debug ) cout << "### Add: " << ptr->left->val << " " <<  (db[ptr].first + 1) << endl;
    }
    if( ptr->right ) { 
      l.push_back(ptr->right);
      db[ptr->right] = { db[ptr].first + 1, ptr }; 
      if ( debug ) cout << "### Add: " << ptr->right->val << " " <<  (db[ptr].first + 1) << endl;
    }
  }

  list<TreeNode*> plist;
  list<TreeNode*> qlist;

  ptr = p;
  if ( debug ) cout << "p trace: " << ptr->val << " ";
  plist.push_front(ptr);
  while(ptr!=root) { 
    ptr = db[ptr].second; // Try Ancestor
    if ( debug ) cout << ptr->val << " ";
    plist.push_front(ptr);
  }
  if ( debug ) cout << endl;
  
  ptr = q;
  if ( debug ) cout << "q trace: " << ptr->val << " ";
  qlist.push_front(ptr);
  while(ptr!=root) { 
    ptr = db[ptr].second; // Try Ancestor
    if ( debug ) cout << ptr->val << " ";
    qlist.push_front(ptr);
  }
  if ( debug ) cout << endl;

  ptr = root;
  auto ptr1 = plist.begin();
  auto ptr2 = qlist.begin();
 
  if ( debug ) cout << (*ptr1)->val << " " << (*ptr2)->val << endl;
  while((*ptr1)==(*ptr2)) { 
    ptr = *ptr1;
    if ( debug ) cout << (*ptr1)->val << " " << (*ptr2)->val << endl;
    if ( ptr1==plist.end() || ptr2==qlist.end() ) break;
    ptr1++; ptr2++;
  }

  return ptr;
}

// https://leetcode.com/discuss/45386/4-lines-c-java-python-ruby
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
  if (!root || root == p || root == q) return root;
  TreeNode* left = lowestCommonAncestor(root->left, p, q);
  TreeNode* right = lowestCommonAncestor(root->right, p, q);
  return !left ? right : !right ? left : root;
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

  n3.left = &n5;
  n3.right= &n1;
  n5.left = &n6;
  n5.right= &n2;
  n2.left = &n7;
  n2.right= &n4;
  n1.left = &n0;
  n1.right= &n8;

  cout << lowestCommonAncestor(&n3,&n5,&n1)->val << " 3" << endl;
  cout << lowestCommonAncestor(&n3,&n5,&n4)->val << " 5" << endl;
  cout << lowestCommonAncestor(&n3,&n6,&n4)->val << " 5" << endl;
  cout << lowestCommonAncestor(&n3,&n6,&n7)->val << " 5" << endl;
  cout << lowestCommonAncestor(&n3,&n6,&n0)->val << " 3" << endl;
  cout << lowestCommonAncestor(&n3,&n6,&n1)->val << " 3" << endl;
  cout << lowestCommonAncestor(&n3,&n0,&n8)->val << " 1" << endl;
  cout << lowestCommonAncestor(&n3,&n1,&n8)->val << " 1" << endl;

  return 0;
}
