
#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
#include <set>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

bool compare(const Interval& a, const Interval& b){
  return a.start < b.start;
}

bool canAttendMeetings(vector<Interval>& intervals) {
  if(intervals.size()<2) return true;
  sort(intervals.begin(),intervals.end(),compare);
  for(int i=1;i<intervals.size();i++){
    if(intervals[i].start < intervals[i-1].end) return false;
  }
  return true;
}

int minMeetingRooms(vector<Interval>& intervals) {
  if(intervals.size()<2) return intervals.size();
  sort(intervals.begin(),intervals.end(),compare);
  bool available = false; 
  multiset<int> rooms {intervals[0].end};
  auto itr = rooms.begin();
  for(int i=1;i<intervals.size();i++){
    available = false;
    for(itr=rooms.begin();itr!=rooms.end();itr++){
      if(intervals[i].start >= *itr) {
        available = true;
        break;
      }
    }
    if(available){
      rooms.erase(itr);
      //cout << "Erase << " << *itr << endl;
    }
    rooms.insert(intervals[i].end);
    //for(auto v:rooms) cout << v << " "; cout << endl;
  }
  return rooms.size();
}

int main(){
  vector<Interval> i1; 
  i1.push_back(Interval(0,30));
  i1.push_back(Interval(5,10));
  i1.push_back(Interval(15,20));
  cout << canAttendMeetings(i1) << endl;
  cout << minMeetingRooms(i1) << endl;
  return 0;
}
