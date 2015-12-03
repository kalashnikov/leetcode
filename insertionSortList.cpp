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

// Well, life gets difficult pretty soon whenever the same operation on array is transferred to linked list.
// Start from the second element (simply a[1] in array and the annoying head -> next -> val in linked list), 
// each time when we see a node with val smaller than its previous node, 
// we scan from the head and find the position that the current node should be inserted. 
//
// Since a node may be inserted before head, 
// we create a new_head that points to head. The insertion operation, however, is a little easier for linked list.
ListNode* insertionSortList(ListNode* head) {
  ListNode* new_head = new ListNode(0);
  new_head -> next = head;
  ListNode* pre = new_head;
  ListNode* cur = head;
  while (cur) {
    if (cur -> next && cur -> next -> val < cur -> val) {
      while (pre -> next && pre -> next -> val < cur -> next -> val)
        pre = pre -> next;
      /* Insert cur -> next after pre.*/
      ListNode* temp = pre -> next;
      pre -> next = cur -> next;
      cur -> next = cur -> next -> next;
      pre -> next -> next = temp;
      /* Move pre back to new_head. */
      pre = new_head;
    }
    else cur = cur -> next;
  }
  ListNode* res = new_head -> next;
  delete new_head;
  return res;
}

// 88ms 
ListNode* insertionSortList(ListNode* head) {
  if(!head || !head->next) return head;

  ListNode dummy(0); dummy.next = NULL;
  ListNode *ptr, *aux, *cur = head;

  while(cur) {
    // Advance until next is larger or next is NULL
    aux = &dummy;
    ptr = dummy.next; 
    while(ptr && ptr->next && ptr->val <= cur->val) { 
      aux = aux->next;
      ptr = ptr->next;
    }

    if ( !ptr ) {
      // Next is NULL
      aux->next = cur; 
      cur = cur->next;
      aux->next->next = NULL;
    } else {
      // Next is larger
      aux->next = cur;
      cur = cur->next;
      aux->next->next = ptr;
    }
  }

  return dummy.next;
}

int main(){

  ListNode l1(6); 
  ListNode l2(5); 
  ListNode l3(4); 
  ListNode l4(3); 
  ListNode l5(2); 
  ListNode l6(1); 
  ListNode l7(2);
  l1.next = &l2;
  l2.next = &l3; 
  l3.next = &l4;
  //l4.next = &l5;
  l5.next = &l6;
  l6.next = &l7;

  auto ptr = insertionSortList(&l1);
  while(ptr!=NULL){
    cout << ptr->val << " ";
    ptr = ptr->next;
  }
  cout << endl;

  return 0;
}
