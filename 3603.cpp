#include "common.h"

class Solution {
 public:
  long long minCost(int m, int n, vector<vector<int>>& waitCost) {
    dp.resize(n);
    dp[0] = 1;
    for (auto i = 1; i < n; ++i) {
      dp[i] = i + 1 + dp[i - 1] + waitCost[0][i - 1];
    }

    for (auto i = 1; i < m; ++i) {
      dp[0] += waitCost[i - 1][0] + (i + 1);
      for (auto j = 1; j < n; ++j) {
        dp[j] = min(dp[j] + waitCost[i - 1][j], dp[j - 1] + waitCost[i][j - 1]) + (i + 1) * (j + 1);
      }
    }
    return dp[n - 1] - waitCost[0][0];
  }
  vector<long long> dp;
};

int main() {
  Solution s;
  vector<vector<int>> v = {{1,2}};
//  vector<vector<int>> v = {{3, 5}, {2, 4}};
  //  vector<vector<int>> v(1, vector<int>(100000, 100000));
  cout << s.minCost(1, 2, v) << endl;
}