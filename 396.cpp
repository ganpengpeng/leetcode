#include "common.h"

using namespace std;

class Solution {
 public:
  int maxRotateFunction(vector<int>& nums) {
    int fn = 0;
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) {
      fn += i * nums[i];
      sum += nums[i];
    }
    int rst = fn;
    for (int i = 1; i < nums.size(); ++i) {
      int temp = nums[nums.size() - i] * (nums.size());
      fn = fn - temp + sum;
      rst = std::max(rst, fn);
    }
    return rst;
  }
};

int main() {
  Solution s;
  vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  cout << s.maxRotateFunction(v) << endl;
  return 0;
}