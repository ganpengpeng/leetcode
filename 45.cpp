#include "common.h"

class Solution {
 public:
  int jump(vector<int>& nums) {
    dp.resize(nums.size(), INT_MAX);
    return func(nums, 0);
  }
  int func(vector<int>& nums, int i) {
    int n = nums.size() - 1;
    if (i >= n) {
      return 0;
    }
    if (dp[i] != INT_MAX) {
      return dp[i];
    }
    int limit = i + nums[i];
    for (int j = i + 1; j <= limit; j++) {
      int a = func(nums, j);
      if (a != INT_MAX) {
        dp[i] = min(a + 1, dp[i]);
      }
    }
    return dp[i];
  }
  vector<int> dp;
};

int main() {
  Solution s;
  vector<int> arr = {2,3,1,1,4};
  cout << s.jump(arr) << endl;
}