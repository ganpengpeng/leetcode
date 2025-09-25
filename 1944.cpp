#include "common.h"

class Solution {
 public:
  vector<int> canSeePersonsCount(vector<int>& heights) {
    int n = heights.size();
    vector<int> res(n, 0);
    vector<int> s;
    for (int i = 0; i < n; ++i) {
      if (s.empty() || heights[i] < heights[s.back()]) {
        if (!s.empty()) res[s.back()] += 1;
        s.push_back(i);
        continue;
      }
      while (!s.empty() && heights[i] >= heights[s.back()]) {
        int index = s.back();
        res[index] += 1;
        s.pop_back();
      }
      if (!s.empty()) {
        res[s.back()] += 1;
      }
      s.push_back(i);
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> v = {10, 6, 8, 5, 11, 9};
  auto r = s.canSeePersonsCount(v);
  for (auto t : r) {
    cout << t << " ";
  }
  cout << endl;
}