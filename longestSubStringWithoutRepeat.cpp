#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

/**
 * Solution (DP, O(n)):
 * Ref: https://leetcode.com/discuss/13336/shortest-o-n-dp-solution-with-explanations
 * 
 * Assume L[i] = s[m...i], denotes the longest substring without repeating
 * characters that ends up at s[i], and we keep a hashmap for every
 * characters between m ... i, while storing <character, index> in the
 * hashmap.
 * We know that each character will appear only once.
 * Then to find s[i+1]:
 * 1) if s[i+1] does not appear in hashmap
 *    we can just add s[i+1] to hash map. and L[i+1] = s[m...i+1]
 * 2) if s[i+1] exists in hashmap, and the hashmap value (the index) is k
 *    let m = max(m, k), then L[i+1] = s[m...i+1], we also need to update
 *    entry in hashmap to mark the latest occurency of s[i+1].
 * 
 * Since we scan the string for only once, and the 'm' will also move from
 * beginning to end for at most once. Overall complexity is O(n).
 *
 * If characters are all in ASCII, we could use array to mimic hashmap.
 */
int lengthOfLongestSubstring(string s) {
  if(s.length()<2) return s.length();
  // for ASCII char sequence, use this as a hashmap
  vector<int> charIndex(256, -1); 
  int maxv = 0, curv = -1;
  for(int i=0; i<s.length(); i++) {
    curv = max(m[s[i]], curv); 
    m[s[i]] = i;
    maxv = max(maxv, i - curv);
  }
  return maxv;
}

int main(){
  cout << lengthOfLongestSubstring("abcabcbb") << " 3" << endl;
  cout << lengthOfLongestSubstring("bbbbbbbb") << " 1" << endl;
  return 0;
}
