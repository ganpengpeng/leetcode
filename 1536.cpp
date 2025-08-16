#include "common.h"

class Solution {
 public:
  int stoneGameV(vector<int>& stoneValue) {
    int n = stoneValue.size();
    sum.resize(n + 1);
    for (int i = 1; i <= n; i++) {
      sum[i] = sum[i - 1] + stoneValue[i - 1];
    }
    dp.resize(n, vector(n, 0));
    return func(stoneValue, 0, n - 1);
  }
  int func(vector<int>& s, int l, int r) {
    if (l == r) return 0;
    if (dp[l][r]) return dp[l][r];
    for (int i = l + 1; i <= r; i++) {
      int a = sum[i] - sum[l];
      int b = sum[r + 1] - sum[i];
      int res = 0;
      if (a < b) {
        res = a + func(s, l, i - 1);
      } else if (a > b) {
        res = b + func(s, i, r);
      } else {
        res = a + max(func(s, l, i - 1), func(s, i, r));
      }
      dp[l][r] = max(dp[l][r], res);
    }
    return dp[l][r];
  }
  vector<vector<int>> dp;
  vector<int> sum;
};

int main() {
  Solution solution;
  vector stoneValue = {5, 5};
  cout << solution.stoneGameV(stoneValue) << endl;
}