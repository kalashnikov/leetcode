#include <iostream>
#include <list>
#include <vector>
#include <unordered_map>

using namespace std;

class LRUCache{
  typedef list<int> LI;
  typedef pair<int, LI::iterator > LII;
  typedef unordered_map<int, LII> HLII;
  
  int cap;
  list<int> _q;
  HLII _db;

  public:
    LRUCache(int capacity) {
      cap = capacity;
      _q.clear();
      _db.reserve(capacity);
    }

    void touch(HLII::iterator itr){
      int key = itr->first;
      _q.erase(itr->second.second);
      _q.push_front(key);
      itr->second.second = _q.begin();
    }

    int get(int key) {
      auto itr = _db.find(key);
      if ( itr==_db.end() ) return -1;
      touch(itr);
      return itr->second.first;
    }

    void set(int key, int value) {
      auto itr = _db.find(key);
      if ( itr!=_db.end() ) touch(itr);
      else { 
        if ( _db.size()==cap ) {
          _db.erase(_q.back());
          _q.pop_back();
        }
        _q.push_front(key);
      }
      _db[key] = {value,_q.begin()}; 
    }
};

int main(){

  LRUCache cache(3);
  cache.set(1,1);
  cache.set(2,2);
  cache.set(3,3);
  cout << cache.get(1) << endl;
  cache.set(4,4);
  cout << cache.get(2) << endl;
  
  cout << " ######### " << endl;

  LRUCache c2(2);
  c2.set(2,1);
  c2.set(3,2);
  cout << c2.get(3) << endl;
  cout << c2.get(2) << endl;
  c2.set(4,3);
  cout << c2.get(2) << endl;
  cout << c2.get(3) << endl;
  cout << c2.get(4) << endl;

  cout << " ######### " << endl;
  
  LRUCache c3(1);
  c3.set(2,1);
  cout << c3.get(2) << endl;
  c3.set(3,2);
  cout << c3.get(2) << endl;
  cout << c3.get(3) << endl;

  return 0;
}
