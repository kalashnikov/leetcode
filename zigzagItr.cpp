#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

class ZigzagIterator {
  int idx; 
  vector<int> db;
  public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
      idx = 0; // idx for iterator
      db.reserve(v1.size()+v2.size());
      int n = min(v1.size(),v2.size());
      for(int i=0;i<n;i++){
        db.push_back(v1[i]);
        db.push_back(v2[i]);
      }
      if(v1.size()>n) db.insert(db.end(),v1.begin()+n,v1.end());
      if(v2.size()>n) db.insert(db.end(),v2.begin()+n,v2.end());
    }

    int next() {
      return db[idx++];
    }

    bool hasNext() {
      return idx<db.size();
    }
};


int main(){

  vector<int> v1 { 1,2 };
  vector<int> v2 { 3,4,5,6 };

  ZigzagIterator i(v1, v2);
  while (i.hasNext()) cout << i.next() << " ";
  cout << endl;
  return 0;
}
