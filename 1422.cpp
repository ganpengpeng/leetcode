#include "common.h"

using namespace std;

class Solution {
 public:
  int maxScore(string s) {
    int one = 0;
    for (int i = 1; i < s.size(); ++i) {
      if (s[i] == '1')
        one += 1;
    }

    int max = s[0] == '0' ? 1 + one : one;
    int t = max;
    for (int i = 1; i < s.size() - 1; ++i) {
      if (s[i] == '0')
        t += 1;
      else
        t -= 1;
      max = std::max(max, t);
    }
    return max;
  }
};

int main() {
  Solution s;
  cout << s.maxScore("00") << endl;
  return 0;
}
