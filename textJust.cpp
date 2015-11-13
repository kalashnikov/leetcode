#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <sstream>

using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {

  vector<string> ans;
  list<string> q(words.begin(),words.end());

  if ( maxWidth==0 ) {
    for(int i=0;i<words.size();i++){
      ans.push_back("");
    }
    return ans;
  } else if ( words.size()==1 && words[0]=="" ) {
    stringstream ss;
    for(int i=0;i<maxWidth;i++)
      ss << " ";
    ans.push_back(ss.str());
    return ans;
  }

  while(!q.empty()){
    list<string> tmp;
    int cnt = 0;

    // Push first string
    cnt += q.front().length(); 
    tmp.push_back(q.front()); q.pop_front();

    // Try to push all possible string into this line
    while( !q.empty() && (cnt+q.front().length() + (tmp.size()+1)-1 ) <= maxWidth ) { 
      cnt += q.front().length(); 
      tmp.push_back(q.front()); q.pop_front();
    }

    // Arrange current line
    stringstream ss;
    if(q.empty()){
      // Last line
      int lim = tmp.size()==0 ? 0 : maxWidth-cnt-tmp.size();
      if ( tmp.size()==1 ) {
        ss << tmp.front();
        lim +=1;
      } else { 
        while(!tmp.empty()){
          ss << tmp.front() << " ";
          tmp.pop_front(); 
        }
      } 
      for(int i=0;i<lim;i++)
        ss << " ";
    } else if(tmp.size()==1){
      ss << tmp.front();
      for(int i=0;i<maxWidth-tmp.front().size();i++)
        ss << " ";
    } else {
      int scnt = (maxWidth - cnt); 
      int uscnt = scnt / (tmp.size() - 1);

      while(tmp.size()!=1){
        ss << tmp.front();
        int lim = (scnt > (tmp.size()-1)*uscnt ) ? (uscnt+1) : uscnt;
        for(int i=0;i<lim;i++)
          ss << " ";
        scnt -= lim; 
        tmp.pop_front();
      }
      ss << tmp.front();
    }
    ans.push_back(ss.str());
  }

  return ans;
}

int main(){

  vector<string> t1 {"This", "is", "an", "example", "of", "text", "justification."};
  auto a1 = fullJustify(t1,16);
  for(auto v:a1)  
    cout << v << endl; 
  cout << endl;

  vector<string> t2 {"justification."};
  auto a2 = fullJustify(t2,16);
  for(auto v:a2)  
    cout << v << " ";
  cout << endl;

  vector<string> t3 {"shall", "be."};
  auto a3 = fullJustify(t3,12);
  for(auto v:a3)  
    cout << v << " ";
  cout << endl;

  vector<string> t4 {"a"};
  auto a4 = fullJustify(t4,2);
  for(auto v:a4)  
    cout << v << "|";
  cout << endl;

  vector<string> t5 {"a"};
  auto a5 = fullJustify(t5,1);
  for(auto v:a5)  
    cout << v << "|";
  cout << endl;
  return 0;
}
