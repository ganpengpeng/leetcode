#include "common.h"

class Solution {
 public:
  vector<int> sequentialDigits(int low, int high) {
    vector<int> res;
    for (auto i = 1; i < 9; ++i) {
      int j = i;
      while (j < low && (j % 10 != 9)) {
        j = j * 10 + (j % 10) + 1;
      }
      while (low <= j && j <= high) {
        res.push_back(j);
        if (j % 10 == 9) {
          break;
        }
        j = j * 10 + (j % 10) + 1;
      }
    }
    sort(res.begin(), res.end());
    return res;
  }
};

int main() {
  Solution s;
  auto v = s.sequentialDigits(1000, 13000);
  for (const auto& item : v) {
    cout << item << " ";
  }
  cout << endl;
}