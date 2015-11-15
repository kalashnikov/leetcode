#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Queue {
  private: 
    stack<int> q1;
    stack<int> q2;

  public:
    
    // Push element x to the back of queue.
    void push(int x) {
      q1.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
      if ( q2.size()==0 ) { 
        while(q1.size()!=0){
          q2.push(q1.top());
          q1.pop();
        }
      }
      q2.pop();
    }

    // Get the front element.
    int peek(void) {
      if ( q2.size()==0 ) { 
        while(q1.size()!=0){
          q2.push(q1.top());
          q1.pop();
        }
      }
      return q2.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
      return q1.size()==0 && q2.size()==0;
    }
};

int main(){

  Queue q; 
  q.push(1);
  q.push(2);
  q.push(3);
  cout << q.peek() << endl;
  q.pop();
  cout << q.peek() << endl;
  cout << q.empty() << endl;

  return 0;
}
