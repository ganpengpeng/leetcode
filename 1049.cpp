#include "common.h"

class Solution {
 public:
  int lastStoneWeightII(vector<int>& stones) {
    int n = stones.size();
    int sum = std::accumulate(stones.begin(), stones.end(), 0);
    int cap = sum / 2;
    vector<int> dp(cap + 1, 0);
    for (int i = 0; i < n; ++i) {
      for (int j = cap; j >= 0; --j) {
        if (j < stones[i]) {
          break;
        }
        dp[j] = std::max(dp[j], dp[j - stones[i]] + stones[i]);
      }
    }
    return sum - 2 * dp[cap];
  }
};

int main() {
  Solution solution;
  // vector v = {2, 7, 4, 1, 8, 1};
  vector v = {31, 26, 33, 21, 40};
  cout << solution.lastStoneWeightII(v) << endl;
}