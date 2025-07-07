#include "common.h"

class Solution {
 public:
  int possibleStringCount(string word, int k) {
    const uint64_t max = word.size() - k;
    uint64_t result = 0;
    uint64_t count = 0;
    for (auto i = 1; i < word.size(); ++i) {
      if (word[i - 1] == word[i]) {
        count += 1;
      } else {
        if (count > max) {
          count = max;
        }
        result += count;
        count = 0;
      }
    }
  }
};

int main() {
  Solution s;
  cout << s.possibleStringCount("abbcccc", 5) << endl;
  return 0;
}