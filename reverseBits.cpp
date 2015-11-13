#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

uint32_t reverseBits(uint32_t n){ 
  uint32_t ans = 0;
  for(int i=0;i<32;i++, n>>=1) {
    ans <<= 1;
    ans |= n&1;
  }
  return ans;
}

uint32_t reverseBits_net(uint32_t n) {
  uint32_t m = 0;
  for (int i = 0; i < 32; i++, n >>= 1) {
    m <<= 1;
    m |= n & 1;
  }
  return m;
}

/*
// https://leetcode.com/discuss/27405/o-1-bit-operation-c-solution-8ms
uint32_t reverseBits(uint32_t n) {
  n = (n >> 16) | (n << 16);
  n = ((n & 0xff00ff00) >> 8) | ((n & 0x00ff00ff) << 8);
  n = ((n & 0xf0f0f0f0) >> 4) | ((n & 0x0f0f0f0f) << 4);
  n = ((n & 0xcccccccc) >> 2) | ((n & 0x33333333) << 2);
  n = ((n & 0xaaaaaaaa) >> 1) | ((n & 0x55555555) << 1);
  return n;
}
*/

int main(){
  cout << reverseBits(43261596) << " 964176192." << endl;
  cout << reverseBits(2147483648) << " 1." << endl;
  cout << reverseBits(1) << " 2147483648." << endl;
  return 0;
}
