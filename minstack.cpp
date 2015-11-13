#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

class MinStack {
  int minv; 
  list<int> *db;
  public:
    MinStack():minv(INT_MAX), db(new list<int>()){}
    void push(int x) {
      minv = min(x, minv); 
      db->push_back(x);
    }

    void pop() {
      int v = db->back();
      db->pop_back();
      if ( v==minv ) {
        minv = INT_MAX;
        for(auto v:*db){
          if ( minv > v ) 
            minv = v;
        }
      }
    }

    int top() {
      return db->back();
    }

    int getMin() {
      return minv; 
    }
};

int main(){

  return 0;
}
