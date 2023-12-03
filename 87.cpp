#include "common.h"

using namespace std;

class Solution {
 public:
  bool isScramble(string s1, string s2) {
    if (s1 == s2)
      return true;

    string t1 = s1;
    sort(t1.begin(), t1.end());
    string t2 = s2;
    sort(t2.begin(), t2.end());
    if (t1 != t2)
      return false;

    for (int i = 1; i < s1.size(); ++i) {
      auto x1 = s1.substr(0, i);
      auto y1 = s2.substr(0, i);
      auto x2 = s1.substr(i);
      auto y2 = s2.substr(0, s1.size() - i);
      if (sortAndComp(x1, y1) && isScramble(x1, y1) && isScramble(s1.substr(i), s2.substr(i))) {
        return true;
      } else if (sortAndComp(x2, y2) && isScramble(x2, y2) && isScramble(s1.substr(0, i), s2.substr(s1.size() - i))) {
        return true;
      }
    }
    return false;
  }
  static bool sortAndComp(string s1, string s2) {
    sort(s1.begin(), s1.end());
    sort(s2.begin(), s2.end());
    return s1 == s2;
  }
};

int main() {
  Solution s;
  cout << s.isScramble("great", "rgeat") << endl;
  return 0;
}