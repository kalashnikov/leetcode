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

// 1 -> 2 -> 3 -> 4
ListNode* reverseList(ListNode* head) {
  ListNode *cur = head, *aux, *pre = NULL;
  while(cur!=NULL) {
    aux = cur->next;
    cur->next = pre; 
    pre = cur;
    cur = aux;
  }
  return pre;
}

ListNode* reverseBetween(ListNode* head, int m, int n) {
  if(m==n||head==NULL) return head;
  ListNode dummy(-1); dummy.next = head;
  ListNode *cur= head, *aux, *start, *end;
  ListNode *pre = &dummy;

  int i = n, j = m;

  // Get the start of interval
  while(j>1){
    pre = cur;
    cur = cur->next;
    j--;
  }

  // Get the end of interval 
  end = head; 
  while(i>0) { end = end->next; i--; }
  
  start = pre;
  pre = end;

  cout << start->val << " " << (pre?pre->val:0) << " " << cur->val << endl;
  while(cur!=end&&n>0){
    aux = cur->next;
    cur->next = pre; 
    pre = cur;
    cur = aux;  
    n--;
  }
 
  cout << (cur?cur->val:0) << " " << (end?end->val:0) << endl;
  start->next = pre;

  return dummy.next;
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
  ListNode c3(3);
  ListNode c4(4);
  ListNode c5(5);
  c1.next = &c2;
  c2.next = &c3;
  c3.next = &c4;
  c4.next = &c5;

  print(&c1);
  cout << endl;

  //print(reverseList(&c1));
  print(reverseBetween(&c1, 1, 4));
  cout << endl;

  return 0;
}
