#include "common.h"
#include "numeric"

using namespace std;

class Solution {
 public:
  vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    map<int, vector<int>> t;
    vector<int> indegree(graph.size(), 0);
    for (int i = 0; i < graph.size(); ++i) {
      for (auto node : graph[i]) {
        t[node].push_back(i);
        indegree[i]++;
      }
    }

    queue<int> q;
    for (int i = 0; i < indegree.size(); ++i) {
      if (indegree[i] == 0) {
        q.push(i);
      }
    }
    vector<bool> temp(graph.size(), false);
    while (q.empty() == false) {
      temp[q.front()] = true;
      for (auto node : t[q.front()]) {
        --indegree[node];
        if (indegree[node] == 0) {
          q.push(node);
        }
      }
      q.pop();
    }
    vector<int> ans;
    for (int i = 0; i < temp.size(); ++i) {
      if (temp[i]) {
        ans.push_back(i);
      }
    }
    return ans;
  }
};

int main() {
  Solution s;
  vector<vector<int>> v = {{1, 2}, {2, 3}, {5}, {0}, {5}, {}, {}};
  auto ret = s.eventualSafeNodes(v);
  for (auto r : ret) {
    cout << r << endl;
  }
  return 0;
}