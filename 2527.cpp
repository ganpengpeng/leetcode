#include "common.h"

using namespace std;

class Solution {
 public:
  int xorBeauty(vector<int>& nums) {
    int rst = 0;
    for (int i = 0; i < nums.size(); ++i) {
        rst ^= nums[i];
    }
    return rst;
  }
};

int main() {
  Solution s;
  vector<int> v = {1, 4};
  cout << s.xorBeauty(v) << endl;
  return 0;
}
