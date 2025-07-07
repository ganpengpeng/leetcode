#include "common.h"

class Solution {
 public:
  char kthCharacter(long long k, vector<int> operations) {
    int step = 0, len = 1;
    int ans = 0;
    while (len < k) {
      step += 1;
      len *= 2;
    }
    while (step--) {
      len /= 2;
      if (k > len) {
        k -= len;
        if (operations[step] == 1) {
          ans += 1;
        }
      }
    }
    return 'a' + ans % 26;
  }
};

int main() {
  Solution s;
  cout << s.kthCharacter(3, {1, 0}) << endl;
  return 0;
}