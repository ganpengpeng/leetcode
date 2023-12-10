#include "common.h"

using namespace std;

class Solution {
 public:
  int findLUSlength(string a, string b) {
    string s, l;
    if (a.length() <= b.length()) {
      s = a;
      l = b;
    } else {
      s = b;
      l = a;
    }
    int i = 0;
    int j = 0;
    for (; j < l.length() && i < s.length(); ++j) {
      if (s[i] == l[j]) {
        i += 1;
      }
    }
    if (i == s.length() && j == l.length()) {
      return -1;
    }
    return l.length();
  }
};

int main() {
  Solution s;
  cout << s.findLUSlength("aefeaf", "a") << endl;
  return 0;
}