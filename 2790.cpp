#include "common.h"

class Solution {
 public:
  int maxIncreasingGroups(vector<int>& usageLimits) {
    priority_queue<int, vector<int>> pq(usageLimits.begin(), usageLimits.end());
    int n = 1;
    while (pq.size() >= n) {
      vector<int> temp;
      for (int i = 0; i < n; ++i) {
        if (pq.top() > 1) {
          temp.push_back(pq.top() - 1);
        }
        pq.pop();
      }
      for (const auto& item : temp) {
        pq.push(item);
      }
      n += 1;
    }
    return n - 1;
  }
};

int main() {
  Solution s;
  vector<int> v = {1, 2, 5};
  cout << s.maxIncreasingGroups(v) << endl;
}