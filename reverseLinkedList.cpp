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
  c1.next = &c2;
  c2.next = &c3;
  c3.next = &c4;

  print(&c1);
  cout << endl;

  print(reverseList(&c1));
  cout << endl;

  return 0;
}
