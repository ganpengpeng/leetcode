#include "common.h"

using namespace std;

constexpr int PEAK_MAX = 9999;

class Solution {
 public:
  vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
    int n = isWater.size();
    int m = isWater[0].size();
    vector<vector<int>> land_map(n, vector<int>(m, PEAK_MAX));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (isWater[i][j]) {
          land_map[i][j] = 0;
          q.emplace(i, j);
        }
      }
    }
    while (!q.empty()) {
      auto coord = q.front();
      q.pop();
      if (coord.first > 0 && land_map[coord.first - 1][coord.second] == PEAK_MAX) {
        land_map[coord.first - 1][coord.second] =
            std::min(land_map[coord.first][coord.second] + 1, land_map[coord.first - 1][coord.second]);
        q.emplace(coord.first - 1, coord.second);
      }
      if (coord.first < n - 1 && land_map[coord.first + 1][coord.second] == PEAK_MAX) {
        land_map[coord.first + 1][coord.second] =
            std::min(land_map[coord.first][coord.second] + 1, land_map[coord.first + 1][coord.second]);
        q.emplace(coord.first + 1, coord.second);
      }
      if (coord.second > 0 && land_map[coord.first][coord.second - 1] == PEAK_MAX) {
        land_map[coord.first][coord.second - 1] =
            std::min(land_map[coord.first][coord.second] + 1, land_map[coord.first][coord.second - 1]);
        q.emplace(coord.first, coord.second - 1);
      }
      if (coord.second < m - 1 && land_map[coord.first][coord.second + 1] == PEAK_MAX) {
        land_map[coord.first][coord.second + 1] =
            std::min(land_map[coord.first][coord.second] + 1, land_map[coord.first][coord.second + 1]);
        q.emplace(coord.first, coord.second + 1);
      }
    }
    return land_map;
  }
};

int main() {
  Solution s;
  // vector<vector<int>> v = {{0, 1}, {0, 0}};
  // vector<vector<int>> v = {{0, 0, 1}, {1, 0, 0}, {0, 0, 0}};
  vector<vector<int>> v = {{0, 0, 0, 0, 0, 0, 1, 0},
                           {0, 1, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 0, 0},
                           {0, 0, 0, 0, 0, 0, 1, 0},
                           {0, 0, 1, 0, 0, 0, 0, 0}};
  Print2DVector(s.highestPeak(v));
  return 0;
}