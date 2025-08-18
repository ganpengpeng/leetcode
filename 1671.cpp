#include "common.h"

class Solution {
 public:
  int minimumMountainRemovals(vector<int>& nums) {
    int n = nums.size();
    vector<int> left(n, 1);
    LIS(nums, left);
    std::reverse(nums.begin(), nums.end());
    vector<int> right(n, 1);
    LIS(nums, right);
    std::reverse(right.begin(), right.end());
    int rst = INT_MAX;
    for (auto i = 1; i < n - 1; ++i) {
      if (left[i] > 1 && right[i] > 1) {
        int t = n + 1 - left[i] - right[i];
        if (t < rst) {
          rst = t;
        }
      }
    }
    return rst;
  }

  void LIS(vector<int>& nums, vector<int>& lis) {
    int n = nums.size();
    vector<int> len = {nums[0]};
    for (auto i = 1; i < n; ++i) {
      auto index = lower_bound(len.begin(), len.end(), nums[i]) - len.begin();
      if (index == len.size()) {
        len.push_back(nums[i]);
      } else {
        len[index] = nums[i];
      }
      lis[i] = len.size();
    }
  }
};

int main() {
  Solution s;
  //  vector<int> v = {1, 3, 1};
  //  vector<int> v = {2, 1, 1, 5, 6, 2, 3, 1};
  //  vector<int> v = {100, 92, 89, 77, 74, 66, 64, 66, 64};
  vector<int> v = {4, 3, 2, 1, 1, 2, 3, 1};
  cout << s.minimumMountainRemovals(v) << endl;
}