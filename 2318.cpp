#include "common.h"

class Solution {
 public:
  int distinctSequences(int n) {
    return func(n, 7, 7);
  }
  long long func(int n, int l, int ll) {
    if (0 == n) {
      return 1;
    }
    if (dp[n][l][ll]) {
      return dp[n][l][ll];
    }
    long long sum = 0;
    for (auto i = 1; i <= 6; ++i) {
      if (i == l || i == ll || gcd(i, l) != 1) {
        continue;
      }
      sum += func(n - 1, i, l) % 1000000007;
    }
    dp[n][l][ll] = sum;
    return sum % 1000000007;
  }
  int gcd(int a, int b) {
    if (b > a) {
      swap(a, b);
    }
    while (b) {
      int t = b;
      b = a % b;
      a = t;
    }
    return a;
  }
  long long dp[10001][8][8] = {};
};

int main() {
  Solution s;
  cout << s.distinctSequences(4) << endl;
}