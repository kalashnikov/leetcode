#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>

using namespace std;

// 732ms 
class TwoSum {
  int maxVal; 
  int minVal;
  int sumMax;
  int sumMin;
  unordered_map<int,int> db;
  unordered_map<int,int>::iterator itr;

  public:

    TwoSum():maxVal(INT_MIN),minVal(INT_MAX),sumMax(INT_MIN),sumMin(INT_MAX){
      db.reserve(1024);
    }

    // Add the number to an internal data structure.
    void add(int number) {
      if(number+maxVal > sumMax ) sumMax = number+maxVal;
      if(number+minVal < sumMin ) sumMin = number+minVal;
      if(maxVal == INT_MIN || number>maxVal){
        if ( maxVal != INT_MIN ) sumMax = maxVal + number;
        maxVal = number; 
      }
      if(minVal == INT_MAX || number<minVal){
        if ( minVal != INT_MAX ) sumMin = minVal + number;
        minVal = number; 
      }
      
      //printf("%d %d | %d %d\n", maxVal, minVal, sumMax, sumMin);
      db[number]++;
    }

    // Find if there exists any pair of numbers which sum is equal to the value.
    bool find(int value) {
      if(db.size()==0) return false;
      if(sumMax!=INT_MIN && value > sumMax) return false;
      if(sumMin!=INT_MAX && value < sumMin) return false;
      if(value%2==0 && db.count(value/2) && db[value/2]>1) return true;
      //cout << " => Check " << endl;
      for(auto v:db) {
        if(2*v.first==value) continue;
        if(db.count(value-v.first)){
          return true;
        }
      }
      return false;
    }
};

int main(){
  TwoSum ts;  
  ts.add(1); ts.add(3); ts.add(5);
  cout << ts.find(4) << endl;//-> true
  cout << ts.find(7) << endl;//-> false
  TwoSum ts2;  
  ts2.add(0);
  cout << ts2.find(0) << endl;//-> false
  TwoSum ts3;  
  ts3.add(0);ts3.add(0);
  cout << ts3.find(0) << endl;//-> true 
  TwoSum ts4;  
  ts4.add(3);ts4.add(1);ts4.add(2);
  cout << ts4.find(3) << endl;//-> true 
  TwoSum ts5;  
  ts5.add(0);ts5.add(-1);ts5.add(-1);ts5.add(0);
  cout << ts5.find(-2) << endl;//-> true 
  cout << ts5.find(0) << endl;//-> true 
  cout << ts5.find(-1) << endl;//-> true 
  cout << ts5.find(1) << endl;//-> false
  return 0;
}
