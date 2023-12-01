#include "common.h"

using namespace std;

class Solution {
 public:
  int dx[4] = {-1, 1, 0, 0};
  int dy[4] = {0, 0, -1, 1};
  int islandPerimeter(vector<vector<int>>& grid) {
    int perimeter = 0;
    for (size_t i = 0; i < grid.size(); i++) {
      for (size_t j = 0; j < grid[i].size(); j++) {
        if (grid[i][j] == 1) {
          for (size_t k = 0; k < 4; k++) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) {
              perimeter += 1;
              continue;
            }
            if (grid[x][y] != 1) {
              perimeter += 1;
            }
          }
        }
      }
    }
    return perimeter;
  }
};

int main() {
  Solution s;
  vector<vector<int>> v = {
      {0, 1, 0, 0}, {1, 1, 1, 0}, {0, 1, 0, 0}, {1, 1, 0, 0}};
  cout << s.islandPerimeter(v) << endl;
  return 0;
}