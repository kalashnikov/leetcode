#include <iostream>
#include <vector>
#include <unordered_set>
#include <set>
#include <algorithm>
#include "gtest/gtest.h"

using namespace std;

namespace 
{
  // https://leetcode.com/discuss/72878/7-line-consice-o-kn-c-solution
  // The main concept is that every new value will based on previous value. 
  // So, to determine new value, at most k values (for each prime nums) need to be considered. 
  // Maintain index table for each prime factor.
  // Time: O(nk)
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    vector<int> index(primes.size(), 0), ugly(n, INT_MAX);
    ugly[0]=1;
    for(int i=1; i<n; i++){
      for(int j=0; j<primes.size(); j++) ugly[i]=min(ugly[i],ugly[index[j]]*primes[j]);
      cout << ugly[i] << " | ";
      for(int j=0; j<primes.size(); j++) index[j]+=(ugly[i]==ugly[index[j]]*primes[j]);
      for(auto v:index) cout << v << "(" << ugly[v] << ") "; cout << endl; 
    }
    return ugly[n-1];
  }
  
  // Min stack implement 
  int nthSuperUglyNumber_ans(int n, vector<int>& primes) {
    if(primes.size()==0 || n==1) return 1;

    int i, j, ret_idx = 0, min_idx = 0;
    
    multimap<unsigned long, int> cand; // min-stack
    unsigned long ret[n]; memset(ret, 0, sizeof(ret)); ret[ret_idx++] = 1;

    unsigned long tv, last = 1; 
    while(ret_idx<n) {
      // Add new possible value to stack
      while( ( tv = ret[min_idx]*primes[0] ) > last){
        if ( cand.size() && tv > cand.begin()->first) break;
        cand.emplace(tv, ret[min_idx++]); 
      }
      
      // Record new min value
      last = ret[ret_idx++] = cand.begin()->first;

      // Update min value to next one  
      while(cand.begin()->first==last) { 
        int base = cand.begin()->second;
        unsigned long cur = last / base;
        cand.erase(cand.begin());
        for(int i=0;i<primes.size()-1;i++){
          if(primes[i]==cur){
            cand.emplace(base*primes[i+1], base);
            break;
          }
        }
      }
    }
    return ret[n-1];
  }

  int nthSuperUglyNumber2(int n, vector<int>& primes) {
    if(primes.size()==0 || n==1) return 1;

    int i, j, ret_idx = 0;
    unsigned long tv, idx = 0, last = 1, minv = ULONG_MAX; 
    unsigned long ret[n]; memset(ret, 0, sizeof(ret)); ret[ret_idx++] = 1; 
    while(ret_idx<n) {
      minv = ULONG_MAX;
      for(i=idx; i<ret_idx; i++) {
        if (ret[i]*primes.back() < last) { 
          idx++; continue;
        }
        if(ret[i]*primes[0] > minv) break;
        for(j=0;j<primes.size();j++) {
          tv = ret[i]*primes[j];
          if(tv > last) { 
            minv = min(minv,tv);
            cout << ret[i] << "*" << primes[j] << " ";
            break;
          }
        }
        if ( j == 0 || minv - ret[ret_idx-1] == 1 ) break; 
      }
      cout << endl << ret[idx] << " " << minv << endl; 
      ret[ret_idx++] = minv;
      last = minv;
    }
    return ret[n-1];
  }
  
  static bool cmp(const pair<int, unsigned long>& a, const pair<int, unsigned long>& b){
    return a.second < b.second ;
  }
  int nthSuperUglyNumber3(int n, vector<int>& primes) {
    if(primes.size()==0 || n==1) return 1;

    int i, j, ret_idx = 0;
    unsigned long tv, last = 1, min_idx = 0; 
    
    //multimap<unsigned long, int> cand;
    vector<pair<int, unsigned long>> cand; cand.reserve(n);
    unsigned long ret[n]; memset(ret, 0, sizeof(ret)); ret[ret_idx++] = 1;

    while(ret_idx<n) {
      while( ( tv = ret[min_idx]*primes[0] ) > last){
        if ( cand.size() && tv > cand[0].second) break;
        cand.emplace_back(ret[min_idx++], tv);
      }
      sort(cand.begin(),cand.end(), cmp);

      // Record the min val
      last = ret[ret_idx++] = cand[0].second;
     
      // Update
      for(int i=0;i<cand.size();i++) { 
        if(cand[i].second==last) {
          bool update = false;
          unsigned long cur = last / cand[i].first;
          for(int j=0;j<primes.size()-1;j++){
            if(primes[j]==cur){
              cand[i].second =  cand[i].first*primes[j+1];
              update = true;
              break;
            }
          }
          if (!update)  {
            cand[i].first = INT_MAX; 
            cand[i].second= ULONG_MAX; 
          }
        } else { 
          break;
        }
      }
    }
    return ret[n-1];
  }
}

TEST(DemoTest, TestAll) {
  vector<int> iv {2,7,13,19};
  EXPECT_EQ(32, nthSuperUglyNumber(12, iv) );
}

TEST(TLETest, TestAll) {
  vector<int> iv {5,7,13,17,23,29,31,43,53,59,61,71,73,79,83,97,109,131,137,163,167,181,191,193,197,199,227,233,251,263}; 
  EXPECT_EQ(8845, nthSuperUglyNumber(500, iv) );
}

//TEST(TLETest2, TestAll){
//  vector<int> iv 
//{7,19,29,37,41,47,53,59,61,79,83,89,101,103,109,127,131,137,139,157,167,179,181,199,211,229,233,239,241,251}; 
//  EXPECT_EQ(1092889481, nthSuperUglyNumber(100000, iv) );
//}
