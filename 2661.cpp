#include "common.h"

using namespace std;

class Solution {
 public:
  int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    int num = arr.size();
    int n = mat.size();
    int m = mat[0].size();
    vector<pair<int, int>> coord_index(n * m + 1);
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        coord_index[mat[i][j]] = {i, j};
      }
    }
    vector<int> row_count(n, m);
    vector<int> col_count(m, n);
    for (int i = 0; i < num; ++i) {
      auto& p = coord_index[arr[i]];
      row_count[p.first] -= 1;
      col_count[p.second] -= 1;
      if (row_count[p.first] == 0 || col_count[p.second] == 0) {
        return i;
      }
    }
    return 0;
  }
};

int main() {
  Solution s;
  vector<int> v = {1, 3, 4, 2};
  vector<vector<int>> mat = {{1, 4}, {2, 3}};
  cout << s.firstCompleteIndex(v, mat) << endl;
  return 0;
}