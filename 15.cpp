#include "common.h"

using namespace std;

class Solution {
 public:
  vector<vector<int>> threeSum(vector<int> &nums) {
    if (nums.size() < 3)
      return {};
    vector<vector<int>> rst;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size() - 2;) {
      int j = i + 1;
      int k = nums.size() - 1;
      while (j < k) {
        if (nums[i] + nums[j] + nums[k] == 0) {
          rst.push_back({nums[i], nums[j], nums[k]});
          k -= 1;
          while (j < k && nums[k + 1] == nums[k])
            k -= 1;

          j += 1;
          while (j < k && nums[j - 1] == nums[j])
            j += 1;
        }
        else if (nums[i] + nums[j] + nums[k] > 0) {
          k -= 1;
          while (j < k && nums[k + 1] == nums[k])
            k -= 1;
        } else {
          j += 1;
          while (j < k && nums[j - 1] == nums[j])
            j += 1;
        }
      }

      i += 1;
      while (i < nums.size() - 2 && nums[i - 1] == nums[i])
        i += 1;
    }
    return rst;
  }
};

int main() {
  Solution s;
  vector<int> v{-1,0,1,2,-1,-4};
  s.threeSum(v);
  return 0;
}