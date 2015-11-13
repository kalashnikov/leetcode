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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  if ( headA==NULL || headB==NULL ) return NULL;
  int la = 0, lb = 0;

  ListNode* ptra = headA;
  ListNode* ptrb = headB;
  while(ptra!=NULL) { la++; ptra = ptra->next; }
  while(ptrb!=NULL) { lb++; ptrb = ptrb->next; }

  ptra = headA; 
  ptrb = headB;
  if ( la > lb ) { 
    int dif = la - lb; 
    while(dif!=0){ ptra=ptra->next; dif--; } 
  } else { 
    int dif = lb - la; 
    while(dif!=0){ ptrb=ptrb->next; dif--; }  
  }

  while(ptra!=ptrb && ptra->next!=NULL && ptrb->next!= NULL) {
    ptra = ptra->next; ptrb = ptrb->next;
  }
  return (ptra==ptrb) ? ptra : NULL ; 
}

int main(){

  ListNode a1(1);
  ListNode a2(2);
  ListNode b1(3);
  ListNode b2(4);
  ListNode b3(5);
  ListNode c1(6);
  ListNode c2(7);
  ListNode c3(8);
  a1.next = &a2;
  //a2.next = &c1;
  b1.next = &b2;
  b2.next = &b3;
  b3.next = &c1;
  c1.next = &c2;
  c2.next = &c3;

  cout << getIntersectionNode(&a1, &b1) << endl;

  return 0;
}
