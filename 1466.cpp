#include "common.h"
using namespace std;
class Solution {
 public:
  vector<int> visited;
  int minReorder(int n, vector<vector<int>>& connections) {
    unordered_map<int, set<int>> in, out;
    for (size_t i = 0; i < n - 1; i++) {
      auto& con = connections[i];
      in[con[1]].insert(con[0]);
      out[con[0]].insert(con[1]);
    }
    visited.resize(n);
    return dfs(in, out, 0);
  }
  int dfs(unordered_map<int, set<int>>& in, unordered_map<int, set<int>>& out,
          int city) {
    if (visited[city]) {
      return 0;
    }
    visited[city] = 1;
    int rst = 0;
    if (in.count(city)) {
      for (auto& i : in.at(city)) {
        rst += dfs(in, out, i);
      }
    }
    if (out.count(city)) {
      for (auto& i : out.at(city)) {
        if (visited[i]) {
          continue;
        }
        rst += dfs(in, out, i) + 1;
      }
    }
    return rst;
  }
};

int main() {
  Solution s;
  vector<vector<int>> v = {{0, 1}, {1, 3}, {2, 3}, {4, 0}, {4, 5}};
  cout << s.minReorder(6, v) << endl;
  return 0;
}
