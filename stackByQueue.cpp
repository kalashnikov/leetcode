#include <iostream>
#include <queue>

using namespace std;

// https://leetcode.com/discuss/46975/a-simple-c-solution
class Stack2{
public:
    queue<int> que;
    // Push element x onto stack.
    void push(int x) {
        que.push(x);
        for(int i=0;i<que.size()-1;++i){
            que.push(que.front());
            que.pop();
        }
    }

    // Removes the element on top of the stack.
    void pop() {
        que.pop();
    }

    // Get the top element.
    int top() {
        return que.front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return que.empty();
    }
};

class Stack {
private: 
    queue<int> q1, q2;
public:
    // Push element x onto stack.
    void push(int x) {
      q1.push(x); 
    }

    // Removes the element on top of the stack.
    void pop() {
      if(empty()) return; 
      while(q1.size()>1) {
        q2.push(q1.front());
        q1.pop();
      }
      int val = q1.front();
      q1.pop(); 
      swap(q1,q2);
      return ;
    }

    // Get the top element.
    int top() {
      if(empty()) return -1;
      int val;
      while(!q1.empty()) {
        val = q1.front();
        q2.push(val);
        q1.pop();
      }
      swap(q1,q2);
      return val;
    }

    // Return whether the stack is empty.
    bool empty() {
      return q1.empty();
    }
};

int main(){
  Stack s;
  s.push(1); s.push(2); s.push(3); 
  cout << s.empty() << endl;
  cout << s.top() << endl;
  s.pop();
  cout << s.top() << endl;
  s.pop();
  cout << s.top() << endl;
  s.pop();
  cout << s.empty() << endl;
  return 0;
}
