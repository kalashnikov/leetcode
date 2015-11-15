#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

// Revisited needed
// https://leetcode.com/discuss/42929/6-suggested-solutions-in-c-with-explanations

// Randomization 
int majorityElement(vector<int>& nums) {
  int n = nums.size();
  srand(unsigned(time(NULL)));
  while (true) {
    int idx = rand() % n;
    int candidate = nums[idx];
    int counts = 0; 
    for (int i = 0; i < n; i++)
      if (nums[i] == candidate)
        counts++; 
    if (counts > n / 2) return candidate;
  }
}

// Partial Sorting
int majorityElement(vector<int>& nums) {
  nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
  return nums[nums.size() / 2];
} 

// Sorting - No need 
int majorityElement(vector<int>& nums) {
  int lim = nums.size()/2;
  sort(nums.begin(),nums.end());
  for(int i=0;i<nums.size();i++){
    int cnt = 1;
    while(nums[i]==nums[i+cnt]) cnt++;
    if(cnt>lim) return nums[i];
  }
  return nums[0];
}

//Boyer-Moore Majority Vote Algorithm
//http://www.cs.utexas.edu/~moore/best-ideas/mjrty/
int majorityElement(vector<int>& nums) {
  int major, counts = 0, n = nums.size();
  for (int i = 0; i < n; i++) {
    if (!counts) {
      major = nums[i];
      counts = 1;
    }
    else counts += (nums[i] == major) ? 1 : -1;
  }
  return major;
}

// Hashtable
int majorityElement2(vector<int>& nums) {
  int lim = nums.size()/2;
  unordered_map<int, int> db;
  for(int i=0;i<nums.size();i++){
    db[nums[i]]++;
    if(db[nums[i]]>lim) return nums[i];
  }
  return nums[0];
}

int main(){
  vector<int> i1{1,2,2};
  cout << majorityElement(i1) << endl;
  return 0;
}
