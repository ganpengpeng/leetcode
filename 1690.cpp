#include "common.h"

class Solution {
 public:
  int stoneGameVII(vector<int>& stones) {
    sum.resize(stones.size() + 1);
    for (int i = 1; i <= stones.size(); ++i) {
      sum[i] = sum[i - 1] + stones[i - 1];
    }
    dp.resize(stones.size(), vector<int>(stones.size()));
    return func(0, stones.size() - 1);
  }
  int func(int l, int r) {
    if (l >= r) return 0;
    if (dp[l][r]) return dp[l][r];
    int a = sum[r + 1] - sum[l + 1] - func(l + 1, r);
    int b = sum[r] - sum[l] - func(l, r - 1);
    return dp[l][r] = max(a, b);
  }
  vector<int> sum;
  vector<vector<int>> dp;
};

int main() {
  Solution solution;
  vector<int> stones = {5, 3, 1, 4, 2};
  // vector<int> stones = {7, 90, 5, 1, 100, 10, 10, 2};
  cout << solution.stoneGameVII(stones) << endl;
}