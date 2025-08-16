#include "common.h"

class Solution {
public:
  bool winnerSquareGame(int n) {
    dp.resize(n + 1, -1);
    return func(n);
  }
  bool func(int n) {
    if (n == 0) return false;
    if (dp[n] != -1) return dp[n];
    bool win = false;
    auto max = std::sqrt(n);
    for (int i = 1; i <= max; i++) {
      auto m = i * i;
      if (m > n) {
        break;
      }
      if (!func(n - m)) {
        win = true;
        break;
      }
    }
    dp[n] = win;
    return win;
  }
  vector<int> dp;
};

int main() {
  Solution s;
  cout << s.winnerSquareGame(4) << endl;
}