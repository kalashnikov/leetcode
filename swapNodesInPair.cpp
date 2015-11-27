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

ListNode* swapPairs(ListNode* head) {
  if(!head || head->next==NULL) return head;
  ListNode dummy(0);
  ListNode *pre= &dummy;
  pre->next = head;

  ListNode *ptr = head, *aux, *aux2;
  while( ptr && ptr->next ){
     aux  = ptr->next; 
     aux2 = ptr->next->next;
     pre->next = aux;
     ptr->next = aux2; 
     aux->next = ptr;
     pre = ptr;
     ptr = aux2;
  }
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
  c1.next = &c2;
  c2.next = &c3;
  c3.next = &c4;

  auto ptr = swapPairs(&c1); 
  print(ptr);
  cout << endl;

  return 0;
}
