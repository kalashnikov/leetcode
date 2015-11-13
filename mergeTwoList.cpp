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

void printLN(ListNode* head){
  while(head!=NULL){
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
  return;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
  if ( l1==NULL && l2==NULL ) return NULL;
  if ( l1==NULL ) return l2;
  if ( l2==NULL ) return l1;
  ListNode dummy(INT_MIN);
  ListNode *ptr = &dummy;
  while(l1&&l2){
    if(l1->val < l2->val){
      ptr->next = l1;
      l1 = l1->next;
    } else { 
      ptr->next = l2;
      l2 = l2->next;
    } 
    ptr = ptr->next; 
  }
  ptr->next = l1 ? l1 : l2;
  return dummy.next;
}

int main(){

	ListNode c0(0);
	ListNode c1(1);
	ListNode c2(2);
	ListNode c3(3);
	ListNode c4(4);
	ListNode c5(5);
	ListNode c6(6);
	ListNode c7(7);
  c0.next = &c1;
  c1.next = &c3;
  c3.next = &c5;
  c5.next = &c7;
  c2.next = &c4;
  c4.next = &c6;

  printLN(&c0);
  printLN(&c2);
  
  auto h = mergeTwoLists(&c0, &c2);
  printLN(h);
	
  ListNode c2_(2);
  ListNode c1_(1);
  auto h_= mergeTwoLists(&c1_, &c2_);
  printLN(h_);

  return 0;
}
