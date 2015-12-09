#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <list>

using namespace std;

class NumArray2{
  private:
    unordered_map<int,int> dif;
    vector<int> *backup, *cache;
  public:
    NumArray2(vector<int> &nums) {
      backup = &nums;
      cache  = new vector<int>(nums.size(),0);
      int sum = 0;
      for(int i=0;i<nums.size();i++){
        sum += nums[i];
        (*cache)[i] = sum;
      }
    }

    void update(int i, int val) {
       dif[i] = val - (*backup)[i];
    }

    int getSum(int i){
      int difSum = 0;
      for(auto v:dif){
        if(v.first>i) continue;
        difSum += v.second;
      }
      return difSum + (*cache)[i];
    }

    int sumRange(int i, int j) {
      if ( i < 0 || j < 0 || i > cache->size() || j > cache->size() || i > j ) 
        return 0;
      return getSum(j)-(i==0?0:getSum(i-1));
      //return (*cache)[j]-(i==0?0:(*cache)[i-1]);
    }
};

class NumArray3{
  private:
    vector<int> *backup, *cache;
    map<int,int> dif;
  public:
    NumArray3(vector<int> &nums) {
      backup = &nums;
      cache  = new vector<int>(nums.size(),0);
      int sum = 0;
      for(int i=0;i<nums.size();i++){
        sum += nums[i];
        (*cache)[i] = sum;
      }
    }

    void update(int i, int val) {
      if(i>backup->size()) return;
       dif[i] = val - (*backup)[i];
    }
    
    int sumRange(int i, int j) {
      if ( i < 0 || j < 0 || i > cache->size() || j > cache->size() || i > j ) return 0;
      int sum = (*cache)[j]-(i==0?0:(*cache)[i-1]), difSum = 0;
      auto v = dif.lower_bound(i);
      auto u = dif.upper_bound(j);
      //cout << "BOUND: " << lowbound->second << " " << upperbound->second << endl;
      for(;v!=u;v++){
        difSum += v->second;
      }
      return difSum + sum;
    }
};

// Binary Indexed Tree
// https://leetcode.com/discuss/70191/share-my-c-solution-1700ms-using-tree-array
// Ref: http://www.csie.ntnu.edu.tw/~u91029/Sequence.html
class NumArray4{
  public:
    NumArray4(vector<int> &nums) {
      sz = nums.size();
      num = vector<int>(sz+1, 0);
      sum = vector<int>(sz+1, 0);
      
      //for(auto v:num) cout << v << " "; cout << endl;
      for(int i=0; i<sz; i++) {
        //cout << nums[i] << " " << bitset<16>(nums[i]) << " | ";
        update(i, nums[i]);
        //for(auto v:sum) cout << v << " "; cout << endl;
      }

      for(auto v:sum) cout << v << " "; cout << endl;
      for(auto v:num) cout << v << " "; cout << endl;
    }

    void update(int idx, int val) {
      int oldv = num[idx+1];
      cout << "Update " << idx << ": ";
      for(int i = idx+1; i<=sz; i+= (i&-i)) {
        cout << i << "(" << bitset<4>(i) << ") ";
        sum[i] = sum[i] - oldv + val;
      }
      num[idx+1] = val;
      cout << endl;
    }

    int sumRange(int i, int j) {
      return getSum(j+1) - getSum(i);
    }

    int getSum(int idx) {
      int ret = 0;
      cout << "Get " << idx << ": ";
      for(int i=idx; i>0; i-=(i&-i)) {
        cout << i << "(" << bitset<4>(i) << ") ";
        ret += sum[i];
      }
      cout << endl;
      return ret;
    }
  private :
    int sz;
    vector<int> num;
    vector<int> sum;
};

class NumArray {
  int size;
  vector<int> num; 
  vector<int> sum;
public:
    NumArray(vector<int> &nums) {
      size = nums.size();
      num = vector<int>(size+1, 0);
      sum = vector<int>(size+1, 0);
      for(int i=0;i<size;i++)
        update(i, nums[i]);
    }

    void update(int i, int val) {
      int oldv = num[i+1]; 
      for(int j=i+1;j<=size;j+=(j&-j))
        sum[j] = sum[j] - oldv + val;
      num[i+1] = val;
    }

    int sumRange(int i, int j) {
       return getSum(j+1) - getSum(i); 
    }

    int getSum(int i){
      int ret = 0;
      for(int j=i;j>0;j-=(j&-j))
        ret += sum[j];
      return ret;
    }
};

int main(){

  // Your NumArray object will be instantiated and called as such:
  // // NumArray numArray(nums);
  // // numArray.sumRange(0, 1);
  // // numArray.update(1, 10);
  // // numArray.sumRange(1, 2);

  vector<int> nums {-2, 0, 3, -5, 2, -1};
  for(auto v:nums) cout << v << " "; cout << endl;
  NumArray numArray(nums);
  //for(int i=0;i<nums.size();i++) cout << numArray.sumRange(i,i) << " "; cout << endl;
  cout << numArray.sumRange(0, 2) << " 1" << endl;// -> 1
  numArray.update(4,4);
  cout << numArray.sumRange(2, 5) << " 1" << endl;// ->  1
  cout << numArray.sumRange(0, 5) << " -1" << endl;// -> -1
  return 0;
}
