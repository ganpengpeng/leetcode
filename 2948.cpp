#include "common.h"

using namespace std;

class Solution {
 public:
  vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
    int n = nums.size();
    vector<pair<int, int>> ans;
    for (int i = 0; i < nums.size(); ++i) {
      ans.emplace_back(nums[i], i);
    }
    ranges::sort(ans);
    map<int, vector<int>> group_nums;
    map<int, vector<int>> group_index;
    int group = 0;
    group_nums[group].push_back(ans[0].first);
    group_index[group].push_back(ans[0].second);
    for (int i = 1; i < n; ++i) {
      if (abs(ans[i - 1].first - ans[i].first) > limit) {
        group += 1;
      }
      group_nums[group].push_back(ans[i].first);
      group_index[group].push_back(ans[i].second);
    }
    vector<int> result(n, 0);
    for (int i = 0; i <= group; ++i) {
      ranges::sort(group_index[i]);
      for (int j = 0; j < group_index[i].size(); ++j) {
        result[group_index[i][j]] = group_nums[i][j];
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  vector<int> v = {1,5,3,9,8};
  PrintVector(s.lexicographicallySmallestArray(v, 2));
  return 0;
}