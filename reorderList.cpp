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

void reorderList_origin(ListNode* head) {
  if(head==NULL||head->next==NULL) return ;

  ListNode *cur = head, *nextn, *aux;
  while(cur && cur->next){
    nextn = cur->next; 
    while(nextn->next && nextn->next->next) nextn = nextn->next; 

    if ( nextn->next ) { 
      aux  = cur->next;
      cur->next = nextn->next;
      cur->next->next = aux;
      nextn->next = NULL;
      cur = aux;
    } else break;
  }
}

// Vector is a little faster.
void reorderList(ListNode* head) {
  if(head==NULL||head->next==NULL) return ;

  //list<ListNode*> q;
  //ListNode *cur = head, *nextn, *aux;
  //while(cur){ q.push_front(cur); cur = cur->next; }
  //q.pop_front();

  vector<ListNode*> q;
  ListNode *cur = head, *nextn, *aux;
  while(cur){ q.push_back(cur); cur = cur->next; }
  int idx = q.size()-2;

  cur = head;
  while(cur && cur->next){
    //if(q.empty() || q.front()==cur) break;
    //nextn = q.front(); q.pop_front();
    if(q.empty() || q[idx]==cur) break;
    nextn = q[idx--];

    if ( nextn->next ) { 
      aux  = cur->next;
      cur->next = nextn->next;
      cur->next->next = aux;
      nextn->next = NULL;
      cur = aux;
    } 
  }
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

  reorderList(&l1);
  
  ListNode* ptr = &l1;
  while(ptr!=NULL){
    cout << ptr->val << " ";
    ptr = ptr->next;
  }
  cout << endl;

  return 0;
}
