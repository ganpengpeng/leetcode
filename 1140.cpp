#include "common.h"

class Solution {
 public:
  int stoneGameII(vector<int>& piles) {
    sum.resize(piles.size() + 1);
    sum[0] = 0;
    for (auto i = 1; i <= piles.size(); ++i) {
      sum[i] = sum[i - 1] + piles[i - 1];
    }
    dp.resize(piles.size(), vector<int>(piles.size()));
    return func(piles, 0, 1);
  }
  int func(vector<int>& piles, int s, int m) {
    int max = m * 2;
    int n = piles.size();
    if (s + max >= n) {
      return sum[n] - sum[s];
    }
    if (dp[s][m]) return dp[s][m];
    int num = 0;
    for (auto i = 1; i <= max; ++i) {
      num = std::max(sum[n] - sum[s] - func(piles, s + i, std::max(m, i)), num);
    }
    return dp[s][m] = num;
  }
  vector<int> sum;
  vector<vector<int>> dp;
};

int main() {
  Solution s;
  vector<int> v = {2, 7, 9, 4, 4};
  cout << s.stoneGameII(v) << endl;
}