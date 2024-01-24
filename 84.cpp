#include "common.h"

using namespace std;

class Solution {
 public:
  int largestRectangleArea(vector<int> &heights) {
    int n = heights.size();
    vector<int> l(heights.size(), -1);
    vector<int> r(heights.size(), n);
    stack<int> s;
    for (auto i = 0; i < n; ++i) {
      while (!s.empty() && heights[s.top()] >= heights[i]) {
        s.pop();
      }
      if (!s.empty()) {
        l[i] = s.top();
      }
      s.push(i);
    }
    s = stack<int>();
    for (auto i = n - 1; i >= 0; --i) {
      while (!s.empty() && heights[s.top()] >= heights[i]) {
        s.pop();
      }
      if (!s.empty()) {
        r[i] = s.top();
      }
      s.push(i);
    }
    int max = 0;
    for (auto i = 0; i < n; ++i) {
      max = std::max(max, heights[i] * (r[i] - l[i] - 1));
    }
    return max;
  }
};

int main() {
  Solution s;
  vector<int> v = {2, 1, 5, 6, 2, 3};
  cout << s.largestRectangleArea(v) << endl;
  return 0;
}
