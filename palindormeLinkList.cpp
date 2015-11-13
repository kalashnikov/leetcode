#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// Recursive
// https://leetcode.com/discuss/65043/my-easy-understand-c-solution
ListNode* temp;
bool check(ListNode* p) {
  if (NULL == p) return true;
  bool isPal = check(p->next) & (temp->val == p->val);
  temp = temp->next;
  return isPal;
}
bool isPalindrome(ListNode* head) {
  temp = head;
  return check(head);
}

// O(n) space 
bool isPalindrome_iterate(ListNode* head) {
  if(head==NULL||head->next==NULL) return true;

  vector<int> vals; 

  ListNode *ptr = head;
  while(ptr!=NULL){
    vals.push_back(ptr->val);
    ptr = ptr->next;
  }

  int i = 0, j = vals.size()-1;
  while(i<=j)
    if(vals[i++]!=vals[j--]) 
      return false;
  return true;
}

void print(ListNode* head){
  if (head!=NULL) { 
    cout << head->val << " ";
    print(head->next);
  }
}

int main(){

  ListNode c1(1);
  ListNode c2(2);
  ListNode c0(2);
  ListNode c3(2);
  ListNode c4(1);
  c1.next = &c2;
  c2.next = &c0;
  c0.next = &c3;
  c3.next = &c4;

  print(&c1);
  cout << endl;

  cout << isPalindrome(&c1) << endl;
  cout << isPalindrome(&c4) << endl;
  return 0;
}
