#include "common.h"

using namespace std;

class Solution {
 public:
  vector<vector<uint64_t>> dp;
  const int mod = 1000000000 + 7;
  int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
    uint64_t rst = 0;
    int dx[] = {-1, 1, 0, 0};
    int dy[] = {0, 0, -1, 1};
    dp.resize(m, vector<uint64_t>(n, 0));
    dp[startRow][startColumn] = 1;
    for (size_t count = 0; count < maxMove; count++) {
      vector<vector<uint64_t>> temp(m, vector<uint64_t>(n));
      for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
          if (dp[i][j] == 0) {
            continue;
          }

          for (int dir = 0; dir < 4; dir++) {
            int x = i + dx[dir];
            int y = j + dy[dir];
            if (x < 0 || x >= m || y < 0 || y >= n) {
              rst = (rst + dp[i][j]) % mod;
            } else {
              temp[x][y] = (temp[x][y] + dp[i][j]) % mod;
            }
          }
        }
      }
      dp = temp;
    }
    return rst;
  }
};

int main() {
  Solution s;
  cout << s.findPaths(1, 2, 50, 0, 0) << endl;
  return 0;
}