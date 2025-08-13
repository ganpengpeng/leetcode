#include "common.h"

class Solution {
 public:
  std::unordered_map<long long, int> dp;

  int minDays(int n) {
    if (n <= 1) return n;
    if (dp.count(n)) return dp[n];
    dp[n] = 1 + minDays(n / 2) + n % 2;
    dp[n] = std::min(dp[n], minDays(n / 3) + 1 + n % 3);
    return dp[n];
  }
};

int main() {
  Solution s;
  cout << s.minDays(10) << endl;
  cout << (2 & 1) << endl;
}