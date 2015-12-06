#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

class Vector2D {
    bool empty;
    vector<vector<int>>::iterator itr1;
    vector<int>::iterator itr2;
    vector<vector<int>>::iterator itr1_end;
    vector<int>::iterator itr2_end;
public:
    Vector2D(vector<vector<int>>& vec2d): empty(false) {
      if(vec2d.size()==0) { empty = true; return; }
      itr1 = vec2d.begin();
      itr2 = itr1->begin();
      // Skip emtpy row
      while (itr1!=itr1_end && itr2==itr1->end()) {
        itr1++; itr2 = itr1->begin();
      }
      itr1_end = vec2d.end();
      itr2_end = vec2d.back().end();
    }

    int next() {
      if(itr1!=itr1_end && itr2==itr1->end()) {
        itr1++; itr2 = itr1->begin();
      }
      int ret = *itr2;
      itr2++;
      // Skip emtpy row
      while (itr1!=itr1_end && itr2==itr1->end()) {
        itr1++; itr2 = itr1->begin();
      }
      return ret;
    }

    bool hasNext() {
      return !empty && !(itr1==itr1_end || itr2==itr2_end);
    }
};

int main(){

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */

  vector<vector<int>> i1 {
    { },
    { },
    {1,2},
    {3}, 
    { },
    {4,5,6},
    { },
    { }
  }; 

  Vector2D i(i1);
  while(i.hasNext()) cout << i.next() << "|";
  cout << endl;
  return 0;
}
