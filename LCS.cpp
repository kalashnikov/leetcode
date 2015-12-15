#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

using namespace std;

int longestConsecutive3(vector<int> num) {
  unordered_map<int,int> m;
  int ret = 0;
  for(auto & n: num){

    //it is in the middle of some consecutive sequence OR we can say it is already visited earlier
    //therefore it does not contribute to a longer sequence
    if(m[n]) continue; 

    //we cannot find adjacent sequences to n, therefore it is a single element sequence by itself
    if(m.find(n-1) == m.end() && m.find(n+1) == m.end()){ // 
      ret = max(ret, m[n] = 1);
      continue;
    }

    //found a sequence at n+1
    //you may wonder what if the sequence at n+1 contains element n?
    //It it contains n, when we add the length by 1 using m[n+1]+1, it is wrong, right?
    //However it is not possible, because if sequence at n+1 contains n, m[n] must have been visited earlier
    //we checked that using if(m[n]) continue; here m[n] is not yet visited;
    //therefore sequence m[n+1] is always on right side, we can safely extend the length by 1
    if(m.find(n-1)==m.end()){ 

      //we want to maintain the TWO boundaries of the sequence
      //the new length of the sequence is the original length m[n+1] incremented by 1
      //left boundary m[n] = m[n+1] +1;
      //right boundary m[n+m[n+1]] = m[n+1]+1;
      //why n+m[n+1]? it is equal to m[n+1]+(n+1)-1 
      //meaning the old left boundary n+1 plus the old length m[n+1] minus 1
      //e.g. for sequence 3,4,5,6 m[3] = 4, and right boundary 6 = 3+m[3]-1 (here n+1 == 3);
      int r = m[n] = m[n+m[n+1]] = m[n+1]+1;
      ret = max(ret, r);
      continue;
    }

    //this is similar to the above case just extend to the right
    if(m.find(n+1)==m.end()){
      int r = m[n] = m[n-m[n-1]] = m[n-1]+1;
      ret = max(ret,r);
      continue;
    }

    //here, we found both sequences at n+1 and n-1, for reasons we explained,
    //the sequences have no overlap.
    //Now, we just need to add the length of current element n (which is 1) to both left and right boundaries
    //the new length will be :  
    //old length of left sequence (m[n-1]) + old length of right sequence (m[n+1]) + 1
    //We also need to mark m[n] as visited, here we can either mark it with 1 or the new length;
    int r = m[n-m[n-1]] = m[n+m[n+1]] = 1+ m[n+1]+ m[n-1];
    m[n] = 1; //basically we just need to mark m[n] as any non-zero number
    // or we can write
    //int r = m[n] = m[n-m[n-1]] = m[n+m[n+1]] = 1+ m[n+1]+ m[n-1];
    ret = max(ret,r);
  }
  return ret;
}

// https://leetcode.com/discuss/16711/possibly-shortest-cpp-solution-only-6-lines
int longestConsecutive(vector<int>& nums) {
  if(nums.size()<2) return nums.size();
  unordered_map<int, int> db; 
  db.reserve(nums.size());
  int maxv = 0, cnt = 0, tmpv, lo, ri;
  for(auto v:nums) {
    if(db[v]) continue;
    lo = db[v-1]; 
    ri = db[v+1]; 
    tmpv = db[v] = db[v+ri] = db[v-lo] = lo + ri + 1; 
    maxv = max(maxv,tmpv); 
  }
  return maxv;
}

int longestConsecutive2(vector<int>& nums) {
  if(nums.size()<2) return nums.size();
  unordered_map<int, bool> db; 
  db.reserve(nums.size());
  for(auto v:nums) db.emplace(v, false); 
  int maxv = 0, cnt = 0, tmpv;
  for(auto v:nums) {
    if(db[v]) continue;
    cnt = 1;
    tmpv = v;
    while(db.count(tmpv+1)) { 
      tmpv++; cnt++;
      db[tmpv] = true;
    }
    tmpv = v; 
    while(db.count(tmpv-1)) { 
      tmpv--; cnt++;
      db[tmpv] = true;
    }
    db[v] = true;
    maxv = max(maxv, cnt);
  }
  return maxv;
}

int main(){
  vector<int> i1 {100, 4, 200, 1, 3, 2};
  cout << longestConsecutive(i1) << " 4"<< endl;
  vector<int> i2 {1,2,0,1};
  cout << longestConsecutive(i2) << " 3"<< endl;
  vector<int> i3 {0,3,7,2,5,8,4,6,0,1};
  cout << longestConsecutive(i3) << " 9"<< endl;
  return 0;
}
