#include "common.h"

using namespace std;
class Solution {
 public:
  int numberOfWays(int n, int x) {
    for (auto i = 1; i <= n; ++i) {
      size_t m = std::pow(i, x);
      if (m <= n) {
        v.push_back(m);
      } else {
        break;
      }
    }

    dp = vector<vector<long long>>(v.size() + 1, vector<long long>(n + 1, -1));
    return func(v.size(), n);
  }

  long long func(size_t i, size_t j) {
    if (j == 0) {
      return 1;
    }
    if (i == 0) {
      return 0;
    }
    if (dp[i][j] != -1) {
      return dp[i][j];
    }
    long long a = 0;
    if (j >= v[i - 1]) {
      a = func(i - 1, j - v[i - 1]);
    }
    long long b = func(i - 1, j);
    dp[i][j] = a + b;
    return (a + b) % mod;
  }

  vector<size_t> v;
  vector<vector<long long>> dp;
  long long mod = 1e9 + 7;
};

int main() {
  Solution s;
  cout << s.numberOfWays(74, 5) << endl;
  return 0;
}