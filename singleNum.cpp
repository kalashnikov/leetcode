#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

vector<int> singleNumber(vector<int>& nums) 
{
  // Pass 1 : 
  // Get the XOR of the two numbers we need to find
  
  // 320ms in 1000-loop
  int diff = 0; for (int num : nums) diff ^= num;
  // 360ms in 1000-loop
  // int diff = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
  
  // Get its last set bit
  diff &= -diff;

  // Pass 2 :
  vector<int> rets = {0, 0}; // this vector stores the two numbers we will return
  for (int num : nums)
  {
    if ((num & diff) == 0) // the bit is not set
    {
      rets[0] ^= num;
    }
    else // the bit is set
    {
      rets[1] ^= num;
    }
  }
  return rets;
}

int singleNumber2(vector<int>& nums) {
  int ones = 0, twos = 0;
  for(int i = 0; i < nums.size(); i++){
    ones = (ones ^ nums[i]) & ~twos;
    twos = (twos ^ nums[i]) & ~ones;
  }
  return ones;
}

int singleNumber1(vector<int>& nums) {
  int ans = 0;
  for(auto v:nums) ans ^= v; 
  return ans;
}

int main(){
  vector<int> i1 { 1,2,3,1,1,2,2 };
  cout << singleNumber2(i1) << endl;

  int a = 3, b = 5;
  cout << a << " " << b << endl;
  a = a ^ b; 
  b = a ^ b;
  a = a ^ b;
  cout << a << " " << b << endl;
  
  vector<int> i2 { 1,2,3,1,2,5 };
  auto a1 = singleNumber(i2);
  cout << a1[0] << " " << a1[1] << endl;

  return 0;
}
