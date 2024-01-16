#include "common.h"

using namespace std;

class Solution {
 public:
  int minDeletion(vector<int>& nums) {
    int count = 0;
    int i = 0;
    for (; i + 1 < nums.size(); i += 2) {
      if (nums[i] != nums[i + 1]) continue;
      count += 1;
      i -= 1;
    }
    if (i != nums.size()) count += 1;
    return count;
  }
};

int main() {
  Solution s;
  vector<int> v;
  cout << s.minDeletion(v) << endl;
  return 0;
}
