#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

class NumArray {
private: 
  vector<int>* cache; 
public:
    NumArray(vector<int> &nums) {
      cache = new vector<int>(nums.size(),0);
      int sum = 0;
      for(int i=0;i<nums.size();i++){
        sum += nums[i];
        (*cache)[i] = sum;
      }
    }

    int sumRange(int i, int j) {
      if ( i < 0 || j < 0 || i > cache->size() || j > cache->size() || i > j ) 
        return 0;
      return (*cache)[j]-(i==0?0:(*cache)[i-1]);
    }
};

int main(){

  vector<int> nums {-2, 0, 3, -5, 2, -1};
  for(auto v:nums) cout << v << " "; cout << endl;
  NumArray numArray(nums);
  for(int i=0;i<nums.size();i++) cout << numArray.sumRange(i,i) << " "; cout << endl;
  cout << numArray.sumRange(0, 2) << endl;// -> 1
  cout << numArray.sumRange(2, 5) << endl;// -> -1
  cout << numArray.sumRange(0, 5) << endl;// -> -3
  return 0;
}
