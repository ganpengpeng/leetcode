#include "common.h"

using namespace std;

class Solution {
 public:
  long long minimumRemoval(vector<int> &beans) {
    sort(beans.begin(), beans.end());
    vector<uint64_t> pre_sum(beans.size() + 1);
    pre_sum[0] = 0;
    for (auto i = 0; i < beans.size(); ++i) {
      pre_sum[i + 1] = beans[i] + pre_sum[i];
    }
    uint64_t rst = UINT64_MAX;
    for (int i = 0; i < beans.size(); ++i) {
      auto n = beans[i];
      uint64_t temp = pre_sum[i] + (pre_sum[beans.size()] - pre_sum[i + 1]) - n * (beans.size() - i - 1);
      rst = std::min(rst, temp);
    }
    return rst;
  }
};

int main() {
  Solution s;
//  vector<int> v = {4, 1, 6, 5};
  vector<int> v = {2, 10, 3, 2};
  cout << s.minimumRemoval(v) << endl;
  return 0;
}