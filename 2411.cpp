#include "common.h"

class Solution {
 public:
  vector<int> smallestSubarrays(vector<int>& nums) {
    vector<int> dp(32);
    vector<int> ans(nums.size());
    for (int i = nums.size() - 1; i >= 0; i--) {
      for (int j = 0; j < 32; j++) {
        if (nums[i] & (1 << j)) {
          dp[j] = i;
        }
      }
      int m = 0;
      for (int dp1 : dp) {
        m = max(m, dp1);
      }
      if (m == 0) {
        m = i;
      }
      ans[i] = m - i + 1;
    }
    return ans;
  }
};

int main() {
  Solution s;
  vector<int> v{1, 0};
  auto a = s.smallestSubarrays(v);
  for (int a1 : a) {
    cout << a1;
  }
  cout << endl;
}