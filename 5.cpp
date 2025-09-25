#include "common.h"

using namespace std;

class Solution {
 public:
  string longestPalindrome(string s) {
    string t = "#";
    for (auto c: s) {
      t += c;
      t += "#";
    }
    int n = t.size();
    int start = 0, len = 0;
    vector<int> lens(n);
    int mid = 0, right = -1;
    for (int i = 0; i < n; ++i) {
      int cur_len;
      if (right > i) {
        int mirror = mid * 2 - i;
        int skip = min(lens[mirror], right - i);
        cur_len = expand(t, i - skip, i + skip);
      } else {
        cur_len = expand(t, i, i);
      }
      lens[i] = cur_len;
      if (i + cur_len > right) {
        mid = i;
        right = i + cur_len;
      }
      if (cur_len > len) {
        start = (i - cur_len + 1) / 2;
        len = cur_len;
      }
    }
    return s.substr(start, len);
  }
  int expand(string& s, int left, int right) {
    while (left >= 0 && right < s.size() && s[left] == s[right]) {
      left -= 1;
      right += 1;
    }
    return (right - left - 2) / 2;
  }
};

int main() {
  Solution s;
  cout << s.longestPalindrome("cbbd") << endl;
  return 0;
}
