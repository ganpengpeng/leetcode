#include "common.h"

class Solution {
 public:
  int maxEvents(vector<vector<int>> events) {
    int ans = 0;
    std::sort(events.begin(), events.end());
    int max_day = 0;
    for (auto& event : events) {
      max_day = max(max_day, event[1]);
    }
    priority_queue<int, vector<int>, std::greater<>> pq;
    for (int i = 1, j = 0; i <= max_day; ++i) {
      while (j < events.size() && events[j].front() <= i) {
        pq.push(events[j].back());
        j += 1;
      }
      while (!pq.empty() && pq.top() < i) {
        pq.pop();
      }
      if (!pq.empty()) {
        ans += 1;
        pq.pop();
      }
    }
    return ans;
  }
};

int main() {
  Solution s;
  cout << s.maxEvents({{1, 4}, {4, 4}, {2, 2}, {3, 4}, {1, 1}}) << endl;
}