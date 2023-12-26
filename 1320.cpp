#include "common.h"

using namespace std;

class Solution {
 public:
  vector<vector<vector<int>>> dp;
  int minimumDistance(string word) {
    dp.resize(27, vector<vector<int>>(27, vector<int>(word.size() + 1)));
    for (int k = 1; k <= word.size(); ++k) {
      for (int i = 0; i < 27; ++i) {
        for (int j = 0; j < 27; ++j) {
          int cur = word[k] - 'A';
          dp[i][j][k] = dp[i][][k - 1];
        }
      }
    }
    return dp[]
  }

  int dis(int n1, int n2) {
    if (n1 == 26) {
      return 0;
    }
    int x1 = n1 / 6;
    int y1 = n1 % 6;
    int x2 = n2 / 6;
    int y2 = n2 % 6;
    return abs(x1 - x2) + abs(y1 - y2);
  }
};

int main() {
  Solution s;

  return 0;
}