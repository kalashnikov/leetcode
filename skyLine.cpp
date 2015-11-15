#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <queue>
#include <map>
#include <set>

using namespace std;

// 西兌 
// https://leetcode.com/discuss/37484/line-of-code-solution-840ms-nlogn-with-multiset-and-multimap
// The basic idea is: 
//    1. Put the start and end of each rectangle into a multimap, we will scan it later. The second parameter of the pair is its height.(i.e. as for [0,5,3] we will put {0, 3} and {5, -3} into the map) 
//    2. For each element in multimap, if the height is greater than zero, we put it into multiset, else we find and erase it from the set. 
//    3. The multiset means at each x value, the existing rectangle. 
//    4. After processing each x value, the max in the set is what we need, just put it into the vector.
vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
  vector<pair<int, int> > ret;
  multimap<int, int> mii;
  for (int i = 0; i < buildings.size(); ++i){
    vector<int> &vi = buildings[i];
    mii.emplace(make_pair(vi[0],  vi[2])); // Start x
    mii.emplace(make_pair(vi[1], -vi[2])); // End   x 
  }
  multiset<int, greater<int>> msi; // larger height first
  msi.emplace(0);
  while (mii.size()){
    int last_height = *msi.begin();
    int cur = mii.begin()->first;      // Current process x 
    while (mii.begin()->first == cur){ // Deal with same x
      int height = mii.begin()->second;// Handle y 
      if (height > 0){
        msi.emplace(height);           // Store if start x 
      }else{
        msi.erase(msi.find(-height));  // Delete if end x 
      }
      mii.erase(mii.begin());          // Finish this rectangle
    }
    if (*msi.begin() != last_height){  
      // height changed means that we up/down from last height, 
      // so here comes critical  
      ret.push_back(make_pair(cur, *msi.begin())); 
    }
  }
  return ret;
}

// Hard to understand  
vector<pair<int, int>> getSkyline2(vector<vector<int>>& buildings) {
  vector<pair<int, int>> res;
  int cur=0, cur_X, cur_H =-1,  len = buildings.size();
  priority_queue< pair<int, int>> liveBlg; // first: height, second, end time
  while(cur<len || !liveBlg.empty())
  { // if either some new building is not processed or live building queue is not empty
    cur_X = liveBlg.empty()? buildings[cur][0]:liveBlg.top().second; // next timing point to process

    if(cur>=len || buildings[cur][0] > cur_X)
    { //first check if the current tallest building will end before the next timing point
      // pop up the processed buildings, i.e. those  have height no larger than cur_H and end before the top one
      while(!liveBlg.empty() && ( liveBlg.top().second <= cur_X) ) liveBlg.pop();
    }
    else
    { // if the next new building starts before the top one ends, process the new building in the vector
      cur_X = buildings[cur][0];
      while(cur<len && buildings[cur][0]== cur_X)  // go through all the new buildings that starts at the same point
      {  // just push them in the queue
        liveBlg.push(make_pair(buildings[cur][2], buildings[cur][1]));
        cur++;
      }
    }
    cur_H = liveBlg.empty()?0:liveBlg.top().first; // outut the top one
    if(res.empty() || (res.back().second != cur_H) ) res.push_back(make_pair(cur_X, cur_H));
  }
  return res;
}


int main(){
  
  vector<vector<int>> i1 { {2,9,10}, {3,7,15}, {5,12,12}, {15,20,10}, {19,24,8} };
  auto a1 = getSkyline(i1);
  for(auto v:a1)  
    cout << v.first << " " << v.second << ", ";
  cout << endl;
  cout << "2 10, 3 15, 7 12, 12 0, 15 10, 20 8, 24 0" << endl << endl;
  
  vector<vector<int>> i2 { {0,2,3}, {2,5,3} };
  auto a2 = getSkyline(i2);
  for(auto v:a2)
    cout << v.first << " " << v.second << ", ";
  cout << endl;
  cout << "0 3, 5 0" << endl << endl;
  
  vector<vector<int>> i3 { {1,2,1}, {1,2,2}, {1,2,3} };
  auto a3 = getSkyline(i3);
  for(auto v:a3)
    cout << v.first << " " << v.second << ", ";
  cout << endl;
  cout << "1 3, 2 0" << endl << endl;
  
  vector<vector<int>> i4 {{0,3,3},{1,5,3},{2,4,3},{3,7,3}};
  auto a4 = getSkyline(i4);
  for(auto v:a4)
    cout << v.first << " " << v.second << ", ";
  cout << endl;
  cout << "0 3, 7 0" << endl << endl;
  
  vector<vector<int>> i5 {{1,2,1},{2147483646,2147483647,2147483647}};
  auto a5 = getSkyline(i5);
  for(auto v:a5)
    cout << v.first << " " << v.second << ", ";
  cout << endl;
  cout << "1 1, 2 0, 2147483646 2147483647, 2147483647 0" << endl << endl;
  
  vector<vector<int>> i6 { {2,4,7}, {2,4,5}, {2,4,6} };
  auto a6 = getSkyline(i6);
  for(auto v:a6)
    cout << v.first << " " << v.second << ", ";
  cout << endl;
  cout << "2 7, 4 0" << endl << endl;
  return 0;
}
