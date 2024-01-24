#include "common.h"

using namespace std;

class Solution {
 public:
  long long maximumSumOfHeights(vector<int> &maxHeights) {
    std::stack<int> s;

    vector<long long> left(maxHeights.size(), 0);
    for (long long i = 0; i < maxHeights.size(); ++i) {
      while (!s.empty() && maxHeights[s.top()] >= maxHeights[i]) {
        s.pop();
      }
      if (!s.empty()) {
        left[i] = left[s.top()] + maxHeights[i] * (i - s.top());
      } else {
        left[i] = maxHeights[i] * (i + 1);
      }
      s.push(i);
    }

    s = stack<int>();

    vector<long long> right(maxHeights.size(), 0);
    for (long long i = maxHeights.size() - 1; i >= 0; --i) {
      while (!s.empty() && maxHeights[s.top()] >= maxHeights[i]) {
        s.pop();
      }
      if (!s.empty()) {
        right[i] = right[s.top()] + maxHeights[i] * (s.top() - i);
      } else {
        right[i] = maxHeights[i] * (maxHeights.size() - i);
      }
      s.push(i);
    }

    long long rst = 0;
    for (int i = 0; i < maxHeights.size(); ++i) {
      rst = std::max(rst, (long long) left[i] + right[i] - maxHeights[i]);
    }
    return rst;
  }
};

int main() {
  Solution s;
  vector<int> v = {5, 3, 4, 1, 1};
  cout << s.maximumSumOfHeights(v) << endl;
  return 0;
}