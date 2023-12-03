#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

class Solution {
public:
  set<char> index;
  int len = 0;

  int lengthOfLongestSubstring(string s) {
    int i = 0, j = 0;
    while (i < s.size() && j < s.size()) {
      if (i < j && index.count(s[j]) == 0) {
        index.insert(s[j]);
        j += 1;
      } else if (i < j && index.count(s[j])) {
        len = max(len, j - i);
        while (s[i] != s[j]) index.erase(s[i++]);
        index.erase(s[i++]);
      } else if (i == j) {
        index.insert(s[j]);
        j += 1;
      }
    }
    return max(len, j - i);
  }
};

int main() {
  Solution s;
  cout << s.lengthOfLongestSubstring("abcabcbb") << endl;
}
