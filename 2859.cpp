#include "common.h"

using namespace std;

class Solution {
 public:
  int sumIndicesWithKSetBits(vector<int>& nums, int k) {
    int sum = 0;
    for (auto i = 0; i < nums.size(); ++i) {
      int count = 0;
      int kNum = i;
      while (kNum) {
        kNum = kNum & (kNum - 1);
        count += 1;
      }
      if (count == k) {
        sum += nums[i];
      }
    }
    return sum;
  }
};

int main() {
  Solution s;
  vector<int> v = {5,10,1,5,2};
  cout << s.sumIndicesWithKSetBits(v, 1) << endl;
  return 0;
}