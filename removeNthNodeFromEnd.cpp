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

ListNode* removeNthFromEnd(ListNode* head, int n) {
  if(head==NULL) return head;
  if(head->next==NULL && n==1) return NULL;
  
  ListNode *ptr1 = head;
  ListNode *ptr2 = head;
  
  // Advance ptr2 to n step before ptr1
  while(n!=0 && ptr2!=NULL ) { ptr2 = ptr2->next; n--; }

  if ( n!=0 ) return head; // N invalid
  if ( ptr2==NULL ) return head->next; // head is delete node 

  // Advance ptr1 to previous node of delete node 
  // while ptr2 should be at the end node 
  while(ptr2->next!=NULL) {
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }
  
  ptr1->next = ptr1->next->next;
  return head; 
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

  auto l = removeNthFromEnd(&l1, 7);
  
  ListNode* ptr = l;
  while(ptr!=NULL){
    cout << ptr->val << " ";
    ptr = ptr->next;
  }
  cout << endl;

  return 0;
}
