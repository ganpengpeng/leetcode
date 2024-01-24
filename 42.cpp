#include "common.h"

using namespace std;

class Solution {
 public:
  int trap(vector<int> &height) {
    if (height.size() <= 2) {
      return 0;
    }

    int n = height.size();
    vector<int> l(n, -1);
    vector<int> r(n, n);
    for (int i = 0; i < n; ++i) {
      int index = i - 1;
      while (index >= 0 && height[index] <= height[i]) {
        index = l[index];
      }
      if (index >= 0 && l[index] != -1) {
        l[i] = l[index];
      } else {
        l[i] = index;
      }
    }
    for (int i = n - 1; i >= 0; --i) {
      int index = i + 1;
      while (index < n && height[index] <= height[i]) {
        index = r[index];
      }
      if (index < n && r[index] != n) {
        r[i] = r[index];
      } else {
        r[i] = index;
      }
    }
    int sum = 0;
    for (auto i = 0; i < n; ++i) {
      if (l[i] < 0 || r[i] >= n) continue;
      int h = std::min(height[l[i]], height[r[i]]);
      sum += h - height[i];
    }
    return sum;
  }
};

int main() {
  Solution s;
  vector<int> intervals = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  cout << s.trap(intervals) << endl;
  return 0;
}