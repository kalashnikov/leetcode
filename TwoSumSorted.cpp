#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target) {
  if ( numbers.size() < 2 ) return numbers;

  int i = 0, j = numbers.size()-1; 
  while(i<j){
    if ( numbers[i]+numbers[j] == target ) { 
      vector<int> ans { i+1, j+1 };
      return ans;
    } else if ( numbers[i]+numbers[j] > target ) {
      j--;
    } else { 
      i++;
    }
  }
  return numbers;
}

int main(){

  vector<int> c1 {2, 7, 11, 9};
  auto a1 = twoSum(c1, 9); 
  cout << a1[0] << " " << a1[1] << endl;

  return 0;
}
