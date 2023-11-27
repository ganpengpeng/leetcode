#include "common.h"

using namespace std;

class Solution {
 public:
  vector<vector<uint64_t>> dp;
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    uint64_t rst = 0;
    dp.resize(m, vector<uint64_t>(n, 0));
    dp[startRow][startColumn] = 1;
    for (size_t count = 0; count < maxMove; count++) {
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          if (i - 1 < 0) {
            rst += dp[i][j];
          }
          if (j - 1 < 0) {
            rst += dp[i][j];
          }
          if (i + 1 >= m) {
            rst += dp[i][j];
          }
          if (j + 1 >= n) {
            rst += dp[i][j];
          }
          if (i - 1 >= 0) {
            dp[i][j] += dp[i - 1][j];
          }
          if (j - 1 >= 0) {
            dp[i][j] += dp[i][j - 1];
          }
          if (i + 1 < m) {
            dp[i][j] += dp[i + 1][j];
          }
          if (j + 1 < n) {
            dp[i][j] += dp[i][j + 1];
          }
        }
      }
    }
    return rst;
  }
};

int main() {
  Solution s;
  cout << s.findPaths(2, 2, 2, 0, 0) << endl;
  return 0;
}