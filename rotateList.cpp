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

ListNode* rotateRight(ListNode* head, int k) {
  if(head==NULL || k<1) return head;

  int n = 0;
  ListNode *ptr = head, *aux;

  while(ptr!=NULL) {
    n++; ptr = ptr->next;
  }

  k %= n; // mod 
  if ( n==1 || k==0 ) return head; // Same

  aux = ptr = head; 
  while(k--) aux = aux->next; // aux advance k nodeS 
  while(aux->next!=NULL) { 
    aux = aux->next;
    ptr = ptr->next;
  }

  ListNode *ans = ptr->next; // new head
  aux->next = head;
  ptr->next = NULL;
  return ans;
}

void print(ListNode* head){
  while(head!=NULL){
    cout << head->val << " ";
    head = head->next;
  }
  cout << endl;
}

int main(){

  ListNode n1(1);
  ListNode n2(2);
  ListNode n3(3);
  ListNode n4(4);
  ListNode n5(5);
  n1.next = &n2;
  //n2.next = &n3;
  //n3.next = &n4;
  //n4.next = &n5;

  print(&n1);
  //print(rotateRight(&n1, 2));
  print(rotateRight(&n1, 2));

  return 0;
}
