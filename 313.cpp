#include "common.h"

class Solution {
 public:
  int nthSuperUglyNumber(int n, vector<int>& primes) {
    vector<long long> dp(n + 1);
    vector<long long> nums(primes.begin(), primes.end());
    vector<int> points(primes.size(), 1);
    dp[1] = 1;
    for (auto i = 2; i <= n; ++i) {
      int min = INT_MAX;
      for (auto j = 0; j < nums.size(); ++j) {
        if (nums[j] < min) {
          min = nums[j];
        }
      }
      dp[i] = min;
      for (auto j = 0; j < nums.size(); ++j) {
        if (nums[j] == dp[i]) {
          points[j] += 1;
          nums[j] = dp[points[j]] * primes[j];
        }
      }
    }
    return dp[n];
  }
};

int main() {
  Solution s;
  vector<int> v = {2, 7, 13, 19};
  cout << s.nthSuperUglyNumber(12, v);
}