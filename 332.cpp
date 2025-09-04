#include "common.h"

class Solution {
 public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    sort(tickets.begin(), tickets.end());
    map<string, vector<string>> m;
    for (auto& item : tickets) {
      m[item.front()].emplace_back(item.back(), false);
    }
    dfs(m, "JFK");
    reverse(res.begin(), res.end());
    return res;
  }
  void dfs(map<string, vector<string>>& m, string now) {
    auto& v = m[now];
    while (!v.empty()) {
      auto next = v.front();
      v.erase(v.begin());
      dfs(m, next);
    }
    res.push_back(now);
  }
  vector<string> res;
};

int main() {
  Solution s;
  vector<vector<string>> t = {{"JFK", "SFO"}, {"JFK", "ATL"}, {"SFO", "ATL"}, {"ATL", "JFK"}, {"ATL", "SFO"}};
  auto v = s.findItinerary(t);
  for (const auto& item : v) {
    cout << item << " ";
  }
  cout << endl;
}