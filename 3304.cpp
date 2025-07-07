#include "common.h"

class Solution {
 public:
  char kthCharacter(int k) {
    int step = 0, len = 1;
    int ans = 0;
    while (len < k) {
      step += 1;
      len *= 2;
    }
    while (step--) {
      len /= 2;
      if (k > len) {
        ans += 1;
        k -= len;
      }
    }
    return 'a' + ans % 26;
  }
};

int main() {
  Solution s;
  cout << s.kthCharacter(10) << endl;
  return 0;
}