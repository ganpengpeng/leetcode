#include "common.h"

class Solution {
 public:
  vector<vector<vector<int>>> dp;
  vector<int> h;
  vector<vector<int>> c;
  int m;
  int n;
  int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
    this->m = m;
    this->n = n;
    h = houses;
    c = cost;
    dp.resize(m, vector<vector<int>>(n + 1, vector<int>(target + 1, -1)));
    for (auto i = 1; i <= n; ++i) {
      func(m - 1, i, target);
    }
    int res = INT_MAX;
    for (auto i = 1; i <= n; ++i) {
      if (dp[m - 1][i][target] != -1) {
        res = min(res, dp[m - 1][i][target]);
      }
    }
    return res == INT_MAX ? -1 : res;
  }
  int func(int hi, int color, int num) {
    if (num < 0) return -1;   // <<--------必须加
    if (hi == -1) {
      return num == 0 ? 0 : -1;
    }
    if (dp[hi][color][num] != -1) {
      return dp[hi][color][num];
    }
    if (h[hi] != 0 && h[hi] != color) {
      dp[hi][color][num] = -1;
      return -1;
    }

    int min_cost = INT_MAX;
    for (auto i = 1; i <= n; ++i) {
      int cost;
      if (i == color && hi != 0) {
        cost = func(hi - 1, i, num);
      } else {
        cost = func(hi - 1, i, num - 1);
      }
      if (cost == -1) {
        continue;
      }
      if (h[hi] == 0) {
        cost += c[hi][color - 1];
      }
      min_cost = std::min(min_cost, cost);
    }
    if (min_cost == INT_MAX) {
      min_cost = -1;
    }
    dp[hi][color][num] = min_cost;
    return min_cost;
  }
};

int main() {
  Solution s;
  vector<int> h = {3, 1, 2, 3};
  vector<vector<int>> c = {{1, 1, 1}, {1, 1, 1}, {1, 1, 1}, {1, 1, 1}};
  cout << s.minCost(h, c, 4, 3, 3) << endl;
  return 0;
}