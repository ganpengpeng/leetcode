#include "common.h"

using namespace std;

class Solution {
 public:
  vector<vector<int>> rst;

  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    vector<int> v;
    dfs(nums, v, 0);
    rst.emplace_back();
    return rst;
  }

  void dfs(vector<int>& nums, vector<int> subset, int index) {
    if (index >= nums.size()) {
      return;
    }

    int new_index = index + 1;
    while (new_index < nums.size() && nums[index] == nums[new_index]) {
      new_index += 1;
    }

    dfs(nums, subset, new_index);

    for (int i = index; i < new_index; ++i) {
      subset.push_back(nums[index]);
      rst.push_back(subset);
      dfs(nums, subset, new_index);
    }
  }
};

int main() {
  Solution s;
  vector<int> v = {1, 2, 2};
  auto rst = s.subsetsWithDup(v);
  for (const auto &kItem : rst) {
    for (const auto &kItem2 : kItem) {
      cout << kItem2 << " ";
    }
    cout << endl;
  }
  return 0;
}