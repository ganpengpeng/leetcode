#include "common.h"

class Solution {
 public:
  int maximumUniqueSubarray(vector<int> nums) {
    unordered_map<int, int> m;
    int max = 0;
    int sum = 0;
    for (auto l = 0, r = 0; r < nums.size(); ++r) {
      if (auto iter = m.find(nums[r]); iter == m.end()) {
        sum += nums[r];
        m[nums[r]] = r;
      } else {
        int t = m[nums[r]];
        for (auto i = l; i <= t; ++i) {
          m.erase(nums[i]);
          sum -= nums[i];
        }
        l = t + 1;
        sum += nums[r];
        m[nums[r]] = r;
      }
      if (sum > max) {
        max = sum;
      }
    }
    return max;
  }
};

int main() {
  Solution s;
  // cout << s.maximumUniqueSubarray({4, 2, 4, 5, 6}) << endl;
  cout << s.maximumUniqueSubarray({187, 470, 25,  436, 538, 809, 441, 167, 477, 110, 275, 133, 666, 345, 411,
                                   459, 490, 266, 987, 965, 429, 166, 809, 340, 467, 318, 125, 165, 809, 610,
                                   31,  585, 970, 306, 42,  189, 169, 743, 78,  810, 70,  382, 367, 490, 787,
                                   670, 476, 278, 775, 673, 299, 19,  893, 817, 971, 458, 409, 886, 434})
       << endl;
}