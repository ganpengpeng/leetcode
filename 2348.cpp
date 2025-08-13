#include "common.h"

class Solution {
 public:
  vector<int> productQueries(int n, vector<vector<int>>& queries) {
    int count = 0;
    vector<int> v;
    while (n) {
      if (n & 1) {
        v.push_back(count);
      }
      count += 1;
      n >>= 1;
    }
    vector<int> rst;
    for (const auto& item : queries) {
      int res = 1;
      for (auto i = item[0], j = item[1]; i <= j; ++i) {
        res = (res * (1LL << v[i]) ) % 1000000007; // 用乘法连乘
      }
      rst.push_back(res);
    }
    return rst;
  }
};

int main() {
  Solution s;
  vector<vector<int>> v = {{0, 1}, {2, 2}, {0, 3}};
  for (const auto& item : s.productQueries(15, v)) {
    cout << item << endl;
  }
  return 0;
}
