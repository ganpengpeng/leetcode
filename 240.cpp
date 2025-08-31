#include "common.h"

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size(), n = matrix[0].size();
    for (int i = 0, j = n - 1; i < m && j >= 0;) {
      if (matrix[i][j] == target) {
        return true;
      }
      if (matrix[i][j] < target) {
        i += 1;
      } else {
        j -= 1;
      }
    }
    return false;
  }
};

int main() {
  Solution s;
  vector<vector<int>> nums{{}, {}};
  cout << s.searchMatrix(nums, 1) << endl;
}