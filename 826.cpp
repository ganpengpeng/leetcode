#include "common.h"

class Solution {
 public:
  int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
    sort(worker.begin(), worker.end(), std::greater<int>());
    vector<pair<int, int>> v;
    for (int i = 0; i < difficulty.size(); i++) {
      v.push_back({profit[i], difficulty[i]});
    }
    sort(v.begin(), v.end(), std::greater<pair<int, int>>());
    int ans = 0;
    for (int i = 0; i < worker.size(); i++) {
      int start = 0;
      for (int j = start; j < v.size(); j++) {
        if (v[j].second > worker[i]) {
          continue;
        }
        ans += v[j].first;
        start = j;
        break;
      }
    }
    return ans;
  }
};

int main() {
  Solution s;
  vector<int> v1 = {2, 4, 6, 8, 10};
  vector<int> v2 = {10, 20, 30, 40, 50};
  vector<int> v3 = {4, 5, 6, 7};
  cout << s.maxProfitAssignment(v1, v2, v3) << endl;
}