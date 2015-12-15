#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

// Revisited needed
// https://leetcode.com/discuss/42929/6-suggested-solutions-in-c-with-explanations
// >1/2 
int majorityElement_new(vector<int>& nums) {
  int cnt = 0, major = 0; 
  for(int v:nums){
    if(!cnt){
      cnt   = 1;
      major = v;
    } else {
      cnt += (v==major) ? 1 : -1;
    }
  }
  return major;
}

// Randomization 
int majorityElement5(vector<int>& nums) {
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
int majorityElement4(vector<int>& nums) {
  nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
  return nums[nums.size() / 2];
} 

// Sorting - No need 
int majorityElement3(vector<int>& nums) {
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
int majorityElement_best(vector<int>& nums) {
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

// >1/3 
vector<int> majorityElement_v(vector<int>& nums) {
  int cnt1=0, cnt2=0;
  int a,b;

  for(int n: nums){
    if (cnt1 == 0 || n == a){
      cnt1++;
      a = n;
    }
    else if (cnt2 == 0 || n==b){
      cnt2++;
      b = n;
    }
    else{
      cnt1--;
      cnt2--;
    }
  }

  cnt1=cnt2=0;
  for(int n: nums){
    if (n==a)   cnt1++;
    else if (n==b) cnt2++;
  }

  vector<int> result;
  if (cnt1 > nums.size()/3)   result.push_back(a);
  if (cnt2 > nums.size()/3)   result.push_back(b);
  return result;
}

vector<int> majorityElement(vector<int>& nums) {
  int num1 = 0, num2 = 0, cnt1 = 0, cnt2 = 0;
  for(auto v:nums){
    if(cnt1==0 || v==num1){
      cnt1++; 
      num1=v;
    } else if (cnt2==0 || v==num2){
      cnt2++; 
      num2=v;
    } else {
      cnt1--;
      cnt2--;
    }
  }

  cnt1 = cnt2 = 0;
  for(auto v:nums) {
    if (v==num1) cnt1++;
    else if (v==num2) cnt2++;
  }

  vector<int> ans;
  if(cnt1>nums.size()/3) ans.push_back(num1); 
  if(cnt2>nums.size()/3) ans.push_back(num2);
  return ans;
}

int main(){
  //vector<int> i1{1,2,2};
  //cout << majorityElement(i1) << endl;
  vector<int> i1{1,2};
  auto v1 = majorityElement(i1);
  for(auto v:v1) cout << v << " "; cout << endl;
  vector<int> i2{1,2,2,2,6,6,6,8};
  auto v2 = majorityElement(i2);
  for(auto v:v2) cout << v << " "; cout << endl;
  vector<int> i3{3,2,3};
  auto v3 = majorityElement(i3);
  for(auto v:v3) cout << v << " "; cout << endl;
  return 0;
}
