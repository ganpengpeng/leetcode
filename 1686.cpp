#include <bitset>

#include "common.h"

class Solution {
 public:
  int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
    values.resize(aliceValues.size());
    for (int i = 0; i < aliceValues.size(); ++i) {
      values[i] = {aliceValues[i] + bobValues[i], aliceValues[i], bobValues[i]};
    }
    sort(values.begin(), values.end(), std::greater<vector<int>>());
    vector<int> res(2);
    for (int i = 0; i < values.size(); ++i) {
      res[i % 2] += values[i][1 + i % 2];
    }
    if (res[0] == res[1]) {
      return 0;
    }
    if (res[0] > res[1]) {
      return 1;
    }
    if (res[0] < res[1]) {
      return -1;
    }
    return 0;
  }
  vector<vector<int>> values;
};

int main() {
  Solution solution;
  vector aliceValues = {5, 5};
  vector bobValues = {5, 5};
  cout << solution.stoneGameVI(aliceValues, bobValues) << endl;
}