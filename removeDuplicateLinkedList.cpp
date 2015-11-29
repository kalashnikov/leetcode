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

ListNode* deleteDuplicates(ListNode* head) {
  if(head==NULL||head->next==NULL) return head;

  ListNode dummy(-1);
  ListNode *pre = &dummy, *cur = head, *aux;

  while(cur){
    aux = cur;
    while(aux->next && aux->val==aux->next->val) 
      aux = aux->next;
    if(aux==cur) {
      // Connect this node
      pre->next = cur; 
      pre = pre->next;
    }
    cur = aux->next; 
    pre->next = NULL;
  }
  return dummy.next;
}

int main(){

  ListNode l1(1); 
  ListNode l2(1); 
  ListNode l3(2); 
  ListNode l4(3); 
  ListNode l5(4); 
  ListNode l6(6); 
  ListNode l7(6);
  l1.next = &l2;
  l2.next = &l3; 
  l3.next = &l4;
  l4.next = &l5;
  l5.next = &l6;
  l6.next = &l7;

  auto l = deleteDuplicates(&l1);
  
  ListNode* ptr = l;
  while(ptr!=NULL){
    cout << ptr->val << " ";
    ptr = ptr->next;
  }
  cout << endl;

  return 0;
}
