#include <iostream>
#include <vector>
#include <list>
#include <random>

using namespace std;

int lower_bound(const vector<int>& res, const int& target) {
  int lo = 0, hi = res.size();
  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (res[mid]>=target) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  return lo;
}

int upper_bound(const vector<int>& res, const int& target) {
  int lo = 0, hi = res.size();
  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (res[mid]<target) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }
  return hi;
}

int binary_search(const vector<int>& res, const int& target) {
  int lo = 0, hi = res.size();
  while (lo < hi) {
    int mid = lo + (hi - lo) / 2;
    if (res[mid]==target) return mid;
    if (res[mid]>target) {
      hi = mid;
    } else {
      lo = mid + 1;
    }
  }
  return -1;
}

int main(){
  std::random_device rd;
  std::mt19937 gen(rd());

  // values near the mean are the most likely
  // standard deviation affects the dispersion of generated values from the mean
  std::normal_distribution<> d(1000,100);
  vector<int> test(1000,0); 
  //for(int i=0;i<1000;i++) test[i] = i;

  for(int i=0;i<1000;i++) test[i] = d(gen);
  sort(test.begin(),test.end());

  int lo = 0, hi = 0;
  for(int i=0;i<1000;i++){
    cout << test[i] << " ";
    lo = lower_bound(test, test[i]);
    hi = upper_bound(test, test[i]);
    if(test[lo]!=test[i] || test[hi]!=test[i]){
    //if(test[lo]!=test[i]){
      cout << lo << " " << hi << " | " << i << " " << test[i] << " is not found." << endl; 
    }
    //if(binary_search(test, test[i])!=i){
    //  cout << i << ": " << test[i] << " is not found." << endl; 
    //}
  }
    cout << endl;

  return 0;
}
