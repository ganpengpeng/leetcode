#include "common.h"

class Solution {
 public:
  bool stoneGame(vector<int>& piles) {
    int n = piles.size();
    dp.resize(n, vector<int>(n, -1));
    return stoneGame(piles, 0, piles.size() - 1);
  }

  bool stoneGame(vector<int>& p, int i, int j) {
    if (i == j) {
      return p[i];
    }
    if (dp[i][j] != -1) {
      return dp[i][j];
    }
    return dp[i][j] = max(p[i] - dp[i + 1][j], p[j] - dp[i][j - 1]);
  }
  vector<vector<int>> dp;
};

int main() {
  Solution s;
  vector<int> v = {5, 3, 4, 5};
  cout << s.stoneGame(v) << endl;
}