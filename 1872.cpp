#include "common.h"

class Solution {
 public:
  int stoneGameVIII(vector<int>& stones) {
    sum.resize(stones.size() + 1);
    for (int i = 1; i <= stones.size(); ++i) {
      sum[i] = sum[i - 1] + stones[i - 1];
    }
    dp.resize(stones.size());
    dp[stones.size() - 1] = sum.back();
    for (int i = stones.size() - 2; i >= 1; --i) {
      dp[i] = std::max(dp[i + 1], sum[i + 1] - dp[i + 1]);
    }
    return dp[1];
  }
  vector<int> sum;
  vector<int> dp;
};

int main() {
  Solution solution;
  vector<int> stones = {};
  solution.stoneGameVIII(stones);
}