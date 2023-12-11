#include "common.h"

using namespace std;

class Solution {
 public:
  vector<vector<int>> rst;
  vector<vector<int>> combine(int n, int k) {
    vector<int> temp;
    dfs(temp, n, k, 0);
    return rst;
  }
  void dfs(vector<int>& temp, int n, int k, int index) {
    if (temp.size() == k) {
      rst.push_back(temp);
      return;
    }
    for (int i = index; i < n; ++i) {
      temp.push_back(i + 1);
      dfs(temp, n, k, i + 1);
      temp.pop_back();
    }
  }
};

int main() {
  Solution s;
  s.combine(4, 2);
  return 0;
}