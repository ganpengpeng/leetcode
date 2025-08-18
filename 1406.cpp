#include "common.h"

class Solution {
 public:
  string stoneGameIII(vector<int>& piles) {
    sum.resize(piles.size() + 1);
    sum[0] = 0;
    for (auto i = 1; i <= piles.size(); ++i) {
      sum[i] = sum[i - 1] + piles[i - 1];
    }
    dp.resize(piles.size(), -1);
    int alice = func(piles, 0);
    int bob = sum.back() - alice;
    if (alice > bob) {
      return "Alice";
    } else if (alice < bob) {
      return "Bob";
    }
    return "Tie";
  }
  int func(vector<int>& piles, int s) {
    int n = piles.size();
    if (s >= n) {
      return 0;
    }
    if (dp[s] != -1) return dp[s];
    int num = INT_MIN;
    for (auto i = 1; i <= 3; ++i) {
      num = std::max(sum[n] - sum[s] - func(piles, s + i), num);
    }
    return dp[s] = num;
  }
  vector<int> sum;
  vector<int> dp;
};

int main() {
  Solution s;
  vector<int> v = {-1, -2, -3};
  cout << s.stoneGameIII(v) << endl;
}