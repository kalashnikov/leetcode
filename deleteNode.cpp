#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* node) {
  if ( node == NULL ) return;
  if ( node->next == NULL ) return;

  ListNode* ptr = node->next;
  node->next = node->next->next;
  ptr->next = NULL;
  node->val = ptr->val;
  return;
}

ListNode* removeElements(ListNode* head, int val) {
  if ( head==NULL ) return NULL;
  ListNode *newHead, *nptr; 
  newHead = nptr = NULL;
  while(head!=NULL) {
    if( head->val!=val ) {
      if ( nptr==NULL ) { 
        newHead = nptr = head;
      } else {
        nptr->next = head;
        nptr = nptr->next;
      }
    } 
    if ( head->val == val && head->next == NULL ) {
      if ( nptr!=NULL ) nptr->next = NULL;
    }
    head = head->next;
  }
  return newHead;
}

int main(){

  ListNode l1(1); 
  ListNode l2(2); 
  ListNode l3(6); 
  ListNode l4(3); 
  ListNode l5(4); 
  ListNode l6(5); 
  ListNode l7(6);
  l1.next = &l2;
  l2.next = &l3; 
  l3.next = &l4;
  l4.next = &l5;
  l5.next = &l6;
  l6.next = &l7;

  removeElements(&l1, 6);

  ListNode* ptr = &l1;
  while(ptr!=NULL){
    cout << ptr->val << " ";
    ptr = ptr->next;
  }
  cout << endl;

  ListNode a1(1);
  auto a = removeElements(&a1, 1);
  if ( a!=NULL ) cout << a->val << endl;
  return 0;
}
