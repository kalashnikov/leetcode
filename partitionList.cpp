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

ListNode* partition(ListNode* head, int x) {
  ListNode less(-1), more(-1);
  ListNode *lptr = &less, *mptr = &more, *ptr = head, *aux;
  while(ptr) {
    aux = ptr->next;
    if(ptr->val<x) {
      lptr->next = ptr;
      lptr = lptr->next;
    } else {
      mptr->next = ptr;
      mptr = mptr->next;
    }
    ptr->next = NULL;
    ptr = aux;
  }
  lptr->next = more.next; 
  return less.next;
}

int main(){

  ListNode l1(1);
  ListNode l2(4);
  ListNode l3(3);
  ListNode l4(2);
  ListNode l5(5);
  ListNode l6(2);
  l1.next = &l2;
  l2.next = &l3;
  l3.next = &l4;
  l4.next = &l5;
  l5.next = &l6;

  auto v = partition(&l1, 3);
  while(v) { 
    cout << v->val << " ";
    v = v->next;
  }
  cout << endl;

  return 0;
}
