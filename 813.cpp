#include "common.h"
#include "numeric"

using namespace std;

class Solution {
 public:
  double largestSumOfAverages(vector<int> &nums, int k) {
    if (k == 1)
      return std::accumulate(nums.begin(), nums.end(), 0) / (double) nums.size();
    for (int i = 0; i <= nums.size() - k + 1; ++i) {
      func(nums, 0, i, 1) + func(nums, i + 1, nums.size() - 1, k - 1);
    }
  }

  double func(vector<int> nums, int l, int r, int k) {

  }
};

int main() {
  Solution s;

  return 0;
}