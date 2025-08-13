#include "common.h"

class Solution {
  // TODO
 public:
  int minimumMountainRemovals(vector<int>& nums) {
    int n = nums.size();
    vector<int> left(n, INT_MAX);
    vector<int> right(n, INT_MAX);
    for (auto i = 1; i < n; ++i) {
      int index = i - 1;
      while (index >= 0 && nums[i] <= nums[index]) {
        index -= 1;
      }
      if (index == -1) {
        left[i] = INT_MAX;
      } else {
        left[i] = (left[index] == INT_MAX ? 0 : left[index]) + i - index - 1;
      }
    }
    for (auto i = n - 1 - 1; i >= 0; --i) {
      int index = i + 1;
      while (index < n && nums[i] <= nums[index]) {
        index += 1;
      }
      if (index == n) {
        right[i] = INT_MAX;
      } else {
        right[i] = (right[index] == INT_MAX ? 0 : right[index]) + index - i - 1;
      }
    }
    int rst = INT_MAX;
    for (auto i = 1; i < n - 1; ++i) {
      if (left[i] + right[i] < rst) {
        rst = left[i] + right[i];
      }
    }
    return rst;
  }
};

int main() {
  Solution s;
  //  vector<int> v = {1, 3, 1};
  vector<int> v = {2, 1, 1, 5, 6, 2, 3, 1};
  cout << s.minimumMountainRemovals(v) << endl;
}