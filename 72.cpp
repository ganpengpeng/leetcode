#include "common.h"

using namespace std;

class Solution {
 public:
  int minDistance(string word1, string word2) {
    vector<vector<int>> v;
    for (int i = 0; i < word1.size() + 1; ++i) {
      v.push_back(vector<int>(word2.size() + 1, 0));
    }
    for (int i = 0; i <= word1.size(); ++i) {
      v[i][0] = i;
    }
    for (int i = 0; i <= word2.size(); ++i) {
      v[0][i] = i;
    }

    for (int i = 1; i <= word1.size(); ++i) {
      for (int j = 1; j <= word2.size(); ++j) {
        int min = std::min(v[i - 1][j], v[i][j - 1]) + 1;
        if (word1[i - 1] == word2[j - 1]) {
          min = std::min(min, v[i - 1][j - 1]);
        } else {
          min = std::min(min, v[i - 1][j - 1] + 1);
        }
        v[i][j] = min;
      }
    }
    return v[word1.size()][word2.size()];
  }
};

int main() {
  Solution s;
  cout << s.minDistance("horse", "ros") << endl;
  return 0;
}