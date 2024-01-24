#include "common.h"

using namespace std;

class Solution {
 public:
  int alternatingSubarray(vector<int> &nums) {
    int plus = 1;
    int start = -1;
    int max = 0;
    int i;
    for (i = 1; i < nums.size(); ++i) {
      if (nums[i - 1] + plus == nums[i]) {
        if (start == -1) {
          start = i - 1;
        }
        plus = -plus;
      } else if (start != -1) {
        max = std::max(max, i - start);
        start = -1;
        plus = 1;
        i -= 1;
      }
    }
    if (start != -1) {
      max = std::max(max, i - start);
    }
    if (max == 0) {
      return -1;
    }
    return max;
  }
};

int main() {
  Solution s;
  vector<int> v = {2,3,4,3,4};
  cout << s.alternatingSubarray(v) << endl;
  return 0;
}