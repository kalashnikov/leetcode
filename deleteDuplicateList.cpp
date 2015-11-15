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

// 1->2->3->3->4->4->6
ListNode* deleteDuplicates_t(ListNode* head) {
  if ( head==NULL || head->next==NULL ) return head;
  ListNode dummy(0);
  ListNode *ptr = head, *ptr2, *aux = &dummy, *d = aux;
  while(ptr!=NULL){
    ptr2 = ptr->next;
    while(ptr2!=NULL && ptr->val==ptr2->val){
      ptr->next = ptr2->next;
      aux->next = ptr2; aux = aux->next;
      cout << "Add D: " << ptr2 << endl;
      ptr2 = ptr->next;
      cout << "Add D (check): " << ptr2 << endl;
    }
    ptr = ptr->next;
  }
  while(d!=NULL) {
    aux = d; 
    d = d->next;
    cout << "D: " << aux << endl;
    delete aux;
  }
  return head;
}

ListNode* deleteDuplicates2(ListNode* head) {
  if ( head==NULL || head->next==NULL ) return head;
  ListNode *ptr = head, *ptr2, *aux;
  while(ptr!=NULL){
    ptr2 = ptr->next;
    while(ptr2!=NULL && ptr->val!=ptr2->val){
      ptr->next = ptr2->next;
      ptr2 = ptr->next;
    }
    ptr = ptr->next;
  }
  return head;
}

// https://leetcode.com/discuss/7188/concise-solution-and-memory-freeing
// Note about freeing memory. We need to free memory when we delete a node. But don't use delete node; construct on an interview without discussing it with the interviewer. 
// A list node can be allocated in many different ways and we can use `delete node;` only if we are sure that the nodes were allocated with new TreeNode(...);.
ListNode *deleteDuplicates(ListNode *head) {
  ListNode* cur = head;
  while (cur) {
    while (cur->next && cur->val == cur->next->val)
      cur->next = cur->next->next;
    cur = cur->next;
  }
  return head;
}


int main(){

  ListNode l1(1); 
  ListNode l2(2); 
  ListNode l3(3); 
  ListNode l4(3); 
  ListNode l5(4); 
  ListNode l6(4); 
  ListNode l7(6);
  l1.next = &l2;
  l2.next = &l3; 
  l3.next = &l4;
  l4.next = &l5;
  l5.next = &l6;
  l6.next = &l7;

  // Print
  ListNode* ptr =  deleteDuplicates(&l1);
  while(ptr!=NULL){
    cout << ptr->val << " ";
    ptr = ptr->next;
  }
  cout << endl;

  return 0;
}
