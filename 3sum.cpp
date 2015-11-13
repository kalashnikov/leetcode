#include <iostream>
#include <vector>
#include <set>
#include <list>

using namespace std;

multiset<int> cache;
void backtrack(vector<vector<int>>& ans, vector<int>& candidates, vector<int>& path, 
    int idx, int nums, int target){
  if ( nums==0 && target==0 ) {
    ans.push_back(path);
    return;
  } else {
    if ( nums == 0 ) return;
    //if ( nums == 1 && cache.find(0-target)==cache.end() ) return ;
    for(int i=idx; i<candidates.size(); i++){
      if ( nums==1 && target+candidates[i]!=0 ) continue; 
      path.push_back(candidates[i]);
      backtrack(ans, candidates, path, i+1, nums-1, target+candidates[i]);
      path.pop_back();
    }
  }
}

vector<vector<int>> threeSum_r(vector<int>& nums) {
  vector<int> path;
  vector<vector<int>> ans; 
  sort(nums.begin(),nums.end());
  //cache.clear();cache.insert(nums.begin(),nums.end());
  backtrack(ans, nums, path, 0, 3, 0);

  sort(ans.begin(),ans.end());
  auto last = std::unique(ans.begin(), ans.end());
  ans.erase(last, ans.end());
  return ans;
}

bool bis(const vector<int>& buf, const int& key, int min, int max)
{
  int mid;
  while (max >= min){
    mid = (min + max) / 2;

    if (buf[mid] < key)
      min = mid + 1;
    else if (buf[mid] > key)
      max = mid - 1;
    else
      return true;
  }
  return false;
}

int threeSumSmaller_1(vector<int>& nums, int target) {
  if ( nums.size()==0 ) return 0;
  sort(nums.begin(),nums.end());

  int i, j, k, sum, cnt = 0;
  for(i=0;i<nums.size()-2;i++){
    if ( nums[i] >= target && nums[i] > 0 ) break; 
    for(j=i+1;j<nums.size()-1;j++){
      if ( nums[i] + nums[j] >= target && nums[j] > 0) break; 
      for(k=j+1;k<nums.size();k++){
        //cout << nums[i] << " " << nums[j] << " " << nums[k] << endl;
        sum = nums[i]+nums[j]+nums[k];
        if ( sum < target ) cnt++;
        else break;
      }
    }
  }
  return cnt;
}

int threeSumSmaller(vector<int>& nums, int target) {
  if ( nums.size()<2 ) return 0;
  sort(nums.begin(),nums.end());

  int i, j, k, sum, cnt = 0;
  for(i=0;i<nums.size()-2;i++){
    j = i+1, k = nums.size()-1;
    while(j<k) {
      sum = nums[i]+nums[j]+nums[k];
      if ( sum >= target ) { 
        k--;
      } else {
        cnt += k-j;
        j++; 
      }
    }
  }
  return cnt;
}

int threeSumClosest(vector<int>& nums, int target) {
  if ( nums.size()==0 ) return 0;
  sort(nums.begin(),nums.end());

  int i, j, k, sum, csum = INT_MIN;
  for(i=0;i<nums.size()-2;i++){
    j = i+1, k = nums.size()-1;
    while(j<k) {
      sum = nums[i]+nums[j]+nums[k];
      if ( csum == INT_MIN || abs(target-sum) < abs(target-csum) ) {
        csum = sum; 
      }
      if ( sum == target ) {
        return target; 
      } else if ( sum < target ) {
        j++; 
        while( j<k && nums[j]==nums[j-1] ) j++;
      } else {
        k--;
        while( j<k && nums[k]==nums[k+1] ) k--;
      }
    }
    while ( i+1 < nums.size() && nums[i+1]==nums[i]) i++;
  }
  return csum;
}

vector<vector<int>> threeSum(vector<int>& nums) {
  vector<vector<int>> ans;
  if ( nums.size()<2 ) return ans;
  sort(nums.begin(),nums.end());

  int i, j, k, sum;
  for(i=0;i<nums.size()-2;i++){
    if ( nums[i]>0 ) break;
    j = i+1, k = nums.size()-1;
    while(j<k) {
      sum =  nums[i]+nums[j]+nums[k];
      if ( sum == 0) { 
        vector<int> solution{ nums[i], nums[j], nums[k] };
        ans.push_back(solution);
        j++;k--;
        while( j<k && nums[k]==nums[k+1] ) k--;
        while( j<k && nums[j]==nums[j-1] ) j++;
      } else if ( sum < 0 ) {
        j++; 
        while( j<k && nums[j]==nums[j-1] ) j++;
      } else {
        k--;
        while( j<k && nums[k]==nums[k+1] ) k--;
      }
    }
    while ( i+1 < nums.size() && nums[i+1]==nums[i]) i++;
  }
  return ans;
}

vector<vector<int>> threeSum_1(vector<int>& nums) {
  vector<vector<int>> ans; 
  if ( nums.size()<3 ) return ans;
  sort(nums.begin(),nums.end());

  auto itr = nums.begin(), citr = nums.end()-1;
  while(itr<citr){
    if ( binary_search(itr, citr, 0-*itr-*citr) ) {
        vector<int> solution{ *itr, 0-*itr-*citr, *citr };
        ans.push_back(solution);
    }
    itr++, citr--;
  }
  sort(ans.begin(),ans.end());
  auto last = std::unique(ans.begin(), ans.end());
  ans.erase(last, ans.end());
  return ans;
}

int main(){

  vector<int> v1 {-1,0,1,2,-1,-4};
  auto r1 = threeSum(v1);
  for(auto v:r1){
    for(auto vv:v){
      cout << vv << " ";
    }
    cout << endl;
  }
  cout << endl;

  vector<int> v2 {13,5,-4,-9,1,-3,10,-7,7,3,1,-13,-11,7,-10,12,-15,13,5,-8,-11,-12,-15,-13,-3,-13,5,-4,6,1,-10,4,13,-7,3,-9,-3,-2,-1,12,9,-15,14,5,0,-10,-5,-8,-12,-15,-1,-8,11,-9,-14,-7,-6,7,-4,-15,-15,-7,-4,14,1,6,12,14,12,-11,11,-2,11,2,-12,-4,7,-2,-5,10,-9,10,9,-13,-14,11,-13,-13,3,-1,9,3,7,-9,-6,-14,4,-8,7,1,-12,-5,14,14,12,10,-12,-3,-7,-2,-8,-9,-7,9,-7,-13,5,-12,-11,-7,2,14,3,-14};
  auto r2 = threeSum(v2);
  for(auto v:r2){
    for(auto vv:v){
      cout << vv << " ";
    }
    cout << endl;
  }
  cout << endl;
  
  vector<int> v3 {4,-2,-9,9,7,9,10,-15,4,-9,-9,8,-6,7,-7,-2,4,-9,-7,-11,13,9,5,-8,10,8,-6,-1,-2,-6,6,-12,7,4,4,-9,-1,-1,-8,10,5,-10,-5,7,12,4,12,-6,10,-10,-2,8,7,10,7,2,-5,9,-14,9,-12,-1,4,2,11,-15,9,-13,-1,-14,4,12,-9,-15,-4,10,4,-7,-11,-9,-1,-6,14,-9,-10,-1,0,-8,-7,-6,8,-12,0,-3,5,-4,-11,-1,-10,4,-8,10,-7,-10,2,4,-14};
  auto r3 = threeSum(v3);
  for(auto v:r3){
    for(auto vv:v){
      cout << vv << " ";
    }
    cout << endl;
  }
  cout << endl;

  vector<int> v4 {7,-1,14,-12,-8,7,2,-15,8,8,-8,-14,-4,-5,7,9,11,-4,-15,-6,1,-14,4,3,10,-5,2,1,6,11,2,-2,-5,-7,-6,2,-15,11,-6,8,-4,2,1,-1,4,-6,-15,1,5,-15,10,14,9,-8,-6,4,-6,11,12,-15,7,-1,-9,9,-1,0,-4,-1,-12,-2,14,-9,7,0,-3,-4,1,-2,12,14,-10,0,5,14,-1,14,3,8,10,-8,8,-5,-2,6,-11,12,13,-7,-12,8,6,-13,14,-2,-5,-11,1,3,-6};
  auto r4 = threeSum(v4);
  for(auto v:r4){
    for(auto vv:v){
      cout << vv << " ";
    }
    cout << endl;
  }
  cout << endl;


  vector<int> c1 {-1,2,1,-4};
  cout << threeSumClosest(c1, 1) << endl;
  
  vector<int> c2 {1,1,1,1};
  cout << threeSumClosest(c2, 0) << endl;

  vector<int> s1 {-2, 0, 1, 3};
  cout << threeSumSmaller(s1,2) << endl;
  return 0;
}
