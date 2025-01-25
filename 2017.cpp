#include "common.h"

using namespace std;

class Solution {
 public:
  long long gridGame(vector<vector<int>>& grid) {
    int n = grid[0].size();
    uint64_t sum0 = 0;
    for (int i = 0; i < n; ++i) {
      sum0 += grid[0][i];
    }
    uint64_t res = sum0;
    uint64_t sum1 = 0;
    for (int i = 0; i < n; ++i) {
      if (i) {
        sum1 += grid[1][i - 1];
      }
      sum0 -= grid[0][i];
      res = std::min(res, std::max(sum1, sum0));
      if (sum1 > sum0) {
        break;
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<vector<int>> v = {{2, 5, 4}, {1, 5, 1}};
  cout << s.gridGame(v) << endl;
  return 0;
}