#include "common.h"

using namespace std;

class Solution {
public:
  string longestPalindrome(string s) {
    string t = "#";
    for (char i : s) {
      t += i;
      t += '#';
    }

    int start = 0, end = -1;

    vector<int> v;
    int right = -1, index = -1;
    for (int i = 0; i < t.size(); ++i) {
      int len;
      if (i >= right) {
        len = expand(t, i, i);
      } else {
        int skip = std::min(v[index * 2 - i], right - i);
        len = expand(t, i - skip - 1, i + skip + 1);
      }

      if (i + len > right) {
        right = i + len;
        index = i;
      }
      v.push_back(len);

      if (len * 2 + 1 > end - start + 1) {
        start = i - len;
        end = i + len;
      }
    }
    string rst;
    for (int i = start; i <= end; ++i) {
      if (t[i] != '#')
        rst += t[i];
    }
    return rst;
  }

  // 返回臂长
  static int expand(const string& s, int l, int r) {
    while (l >= 0 && r < s.size() && s[l] == s[r]) {
      l -= 1;
      r += 1;
    }
    return (r - l - 2) / 2;
  }
};

int main() {
  Solution s;
  cout << s.longestPalindrome("cbbd") << endl;
  return 0;
}
