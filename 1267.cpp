#include "common.h"

using namespace std;

class Solution {
 public:
  int countServers(vector<vector<int>>& grid) {
    int n = grid.size();
    int m = grid[0].size();
    int communicableServersCount = 0;
    vector<int> rowCounts(m, 0), lastServerInCol(n, -1);
    for (int i = 0; i < n; i++) {
      int server_in_col = 0;
      for (int j = 0; j < m; j++) {
        if (grid[i][j] == 1) {
          server_in_col += 1;
          rowCounts[j] += 1;
          lastServerInCol[i] = j;
        }
      }
      if (server_in_col > 1) {
        communicableServersCount += server_in_col;
        lastServerInCol[i] = -1;
      }
    }
    for (int i = 0; i < n; i++) {
      if (lastServerInCol[i] != -1 && rowCounts[lastServerInCol[i]] > 1) {
        communicableServersCount += 1;
      }
    }
    return communicableServersCount;
  }
};

int main() {
  Solution s;
  vector<vector<int>> v = {{1, 1, 0, 0}, {0, 0, 1, 0}, {0, 0, 1, 0}, {0, 0, 0, 1}};
  cout << s.countServers(v) << endl;
  return 0;
}