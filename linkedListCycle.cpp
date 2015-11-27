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

// 16ms
bool hasCycle1(ListNode *head) {
  ListNode *ptr1 = head, *ptr2 = head;
  while( ptr2 && ptr2->next ){
    ptr1 = ptr1->next;
    ptr2 = ptr2->next->next;
    if ( ptr1==ptr2 ) return true;
  }
  return false;
}

// 12ms, fewer checking makes faster ?  
bool hasCycle(ListNode *head) 
{
  ListNode *fast;
  fast = head;
  while (head)
  {
    head = head->next;
    if (fast->next && fast->next->next)
      fast = fast->next->next;
    else
      return false;

    if (fast == head)
      return true;
  }

  return false;
}

ListNode *detectCycle(ListNode *head) {
  ListNode *ptr1 = head, *ptr2 = head;
  while( ptr2 ){
    ptr1 = ptr1->next;
    if(ptr2->next && ptr2->next->next) 
      ptr2 = ptr2->next->next;
    else 
      return NULL;
    if ( ptr1==ptr2 ) break;
  }

  ptr1 = head;
  while(ptr1!=ptr2){
    ptr1 = ptr1->next;
    ptr2 = ptr2->next;
  }
  return ptr1;
}

int main(){

  ListNode l1(1); 
  ListNode l2(2); 
  ListNode l3(3); 
  ListNode l4(4); 
  ListNode l5(5); 
  ListNode l6(6); 
  ListNode l7(7);
  l1.next = &l2;
  //l2.next = &l3; 
  l3.next = &l4;
  l4.next = &l5;
  l5.next = &l6;
  l6.next = &l7;
  l7.next = &l3;

  cout << hasCycle(&l1) << endl;

  auto an = detectCycle(&l1);
  if(an) cout << an->val << endl;
  return 0;
}
