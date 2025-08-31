#include "common.h"

class Solution {
 public:
  int maxConsecutive(int bottom, int top, vector<int>& special) {
    sort(special.begin(), special.end());
    int max = 0;
    for (auto s : special) {
      if (s > bottom) {
        max = std::max(max, s - bottom);
      }
      bottom = s + 1;
    }
    if (top > special.back()) {
      max = std::max(max, top - special.back());
    }
    return max;
  }
};

int main() {
  Solution s;
  cout << s.maxConsecutive() << endl;
}