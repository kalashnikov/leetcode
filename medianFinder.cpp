#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

// MultiSet: 164ms
class MedianFinderS {
 
  multiset<int,greater<int>> maxStack; // lower part
  multiset<int> minStack; // upper part

  public:

    MedianFinderS(){}

    // Adds a number into the data structure.
    void addNum(int num) {
      if(maxStack.size()!=0 && num > *(maxStack.begin())) minStack.insert(num); 
      else maxStack.insert(num);

      // Keep maxStack.size() equal to minStack.size() 
      // Or maxStack.size()+1 equal to minStack.size()
      if(minStack.size()>maxStack.size()) { 
        maxStack.insert(*minStack.begin()); 
        minStack.erase(minStack.begin());
      } else if(maxStack.size()-1>minStack.size()) { 
        minStack.insert(*maxStack.begin()); 
        maxStack.erase(maxStack.begin());
      }
    }

    // Returns the median of current data stream
    double findMedian() {
      if(minStack.size()==maxStack.size()) return double(*minStack.begin()+*maxStack.begin())/2;
      return *maxStack.begin();
    }
};

// Priority Queue(Heap by array): 152ms
class MedianFinder {

  priority_queue<int> maxHeap; //lower part
  priority_queue<int,vector<int>, greater<int>> minHeap; //upper part

  public:

    MedianFinder(){}

    // Adds a number into the data structure.
    void addNum(int num) {
      if(maxHeap.size()!=0 && num > maxHeap.top()) {
        minHeap.emplace(num);
      } else { 
        maxHeap.emplace(num);
      }

      // Keep maxHeap.size() equal to minHeap.size() 
      // Or maxHeap.size()+1 equal to minHeap.size()
      if(minHeap.size()>maxHeap.size()) {
        maxHeap.emplace(minHeap.top());
        minHeap.pop(); 
      } else if(maxHeap.size()-1>minHeap.size()) { 
        minHeap.emplace(maxHeap.top());
        maxHeap.pop(); 
      }
    }

    // Returns the median of current data stream
    double findMedian() {
      if(minHeap.size()==maxHeap.size()) return double(minHeap.top()+maxHeap.top())/2;
      return maxHeap.top();
    }
};

int main(){

  MedianFinder mf1;
  mf1.addNum(2);
  mf1.addNum(3);
  mf1.addNum(4);
  cout << mf1.findMedian() << " 3" << endl;

  MedianFinder mf2;
  mf2.addNum(2);
  mf2.addNum(3);
  cout << mf2.findMedian() << " 2.5" << endl;

  MedianFinder mf3;
  mf3.addNum(-1);
  cout << mf3.findMedian() << " -1" << endl;
  mf3.addNum(-2);
  cout << mf3.findMedian() << " -1.5" << endl;
  mf3.addNum(-3);
  cout << mf3.findMedian() << " -2" << endl;
  mf3.addNum(-4);
  cout << mf3.findMedian() << " -2.5" << endl;
  mf3.addNum(-5);
  cout << mf3.findMedian() << " -3" << endl;

  return 0;
}
