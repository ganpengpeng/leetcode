#include "common.h"

using namespace std;

class Solution {
 public:
  vector<vector<int>> dp;
  int longestCommonSubsequence(string text1, string text2) {
    dp.resize(text1.size() + 1, vector<int>(text2.size() + 1, -1));
    return helper(text1, text2, text1.size() - 1, text2.size() - 1);
  }
  int helper(string& text1, string& text2, int i, int j) {
    if (i < 0 || j < 0) {
      return 0;
    }
    if (dp[i][j] != -1) {
      return dp[i][j];
    }
    int rst;
    if (text1[i] == text2[j]) {
      rst = helper(text1, text2, i - 1, j - 1) + 1;
    } else {
      rst = max(helper(text1, text2, i - 1, j), helper(text1, text2, i, j - 1));
    }
    dp[i][j] = rst;
    return rst;
  }
};

int main() {
  Solution s;
  cout << s.longestCommonSubsequence("abc", "def") << endl;
  return 0;
}