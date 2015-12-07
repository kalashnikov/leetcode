#include <iostream>
#include <vector>
#include <unordered_set>
#include <list>

using namespace std;

// 1088ms
//
// Ref: https://leetcode.com/discuss/71763/share-some-thoughts 
// The actual implementation is similar to the BFS topological sort. 
// Remove the leaves, update the degrees of inner vertexes. 
// Then remove the new leaves. 
// Doing so level by level until there are 2 or 1 nodes left. What's left is our answer!
The time complexity and space complexity are both O(n).
vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
  if(n==1) return vector<int>{0};
  if(n==2) return vector<int>{0,1};
  int degree[n];
  memset(degree, 0, sizeof(int)*n);
  vector<vector<int>> graph(n);
  for(auto v:edges){
    graph[v.first].emplace_back(v.second);
    graph[v.second].emplace_back(v.first);
    ++degree[v.first];
    ++degree[v.second];
  }

  vector<int> leaf, newleaf; 
  for(int i=0;i<n;i++)
    if(degree[i]==1) 
      leaf.emplace_back(i);

  while(n>2) {
    n -= leaf.size();
    newleaf.clear();
    for(auto v:leaf){
      for(auto vv:graph[v]){
        if(--degree[vv]==1) 
          newleaf.emplace_back(vv);
      }
    }
    swap(leaf,newleaf); 
  }
  return leaf;
}

int main(){

  vector<pair<int,int>> i1 {
    {1,0},
    {1,2},
    {1,3}
  };
  auto a1 = findMinHeightTrees(4, i1); 
  for(auto v:a1) cout << v << " "; cout << endl;
  
  vector<pair<int,int>> i2 {
    {0,3},
    {1,3},
    {2,3},
    {4,3},
    {5,4}
  };
  auto a2 = findMinHeightTrees(6, i2); 
  for(auto v:a2) cout << v << " "; cout << endl;
  
  vector<pair<int,int>> i3 {
    {0,1},
    {0,2},
    {0,3},
    {3,4},
    {4,5}
  };
  auto a3 = findMinHeightTrees(6, i3); 
  for(auto v:a3) cout << v << " "; cout << endl;
  return 0;
}
