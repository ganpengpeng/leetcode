#include "common.h"

using namespace std;

class Solution {
 public:
  vector<vector<pair<int, int>>> dp;
  string s1, s2, s3;

  bool isInterleave(string s1, string s2, string s3) {
    this->s1 = s1;
    this->s2 = s2;
    this->s3 = s3;
    dp.resize(s1.size() + 1, vector<pair<int, int>>(s2.size() + 1, {-1, -1}));

    if (s1.size() + s2.size() != s3.size())
      return false;

    return dfs(0, 0, 0, true) || dfs(0, 0, 0, false);
  }

  bool dfs(int idx1, int idx2, int idx3, bool choose_s1) {
    // recursion exit
    if (idx3 >= s3.length()) {
      return idx1 >= s1.length() && idx2 >= s2.length() && idx3 >= s3.length();
    }

    if (choose_s1) {
      if (dp[idx1][idx2].first != -1) {
        return dp[idx1][idx2].first;
      }
    } else {
      if (dp[idx1][idx2].second != -1) {
        return dp[idx1][idx2].second;
      }
    }

    bool rst = false;
    if (choose_s1) {
      for (int i = idx1, j = idx3; i < s1.length() && j < s3.length(); ++i, ++j) {
        if (s1[i] == s3[j]) {
          rst |= dfs(i + 1, idx2, j + 1, !choose_s1);
        } else {
          break;
        }
      }
    } else {
      for (int i = idx2, j = idx3; i < s2.length() && j < s3.length(); ++i, ++j) {
        if (s2[i] == s3[j]) {
          rst |= dfs(idx1, i + 1, j + 1, !choose_s1);
        } else {
          break;
        }
      }
    }

    if (choose_s1) {
      dp[idx1][idx2].first = rst;
    } else {
      dp[idx1][idx2].second = rst;
    }

    return rst;
  }
};

int main() {
  Solution s;
  cout << s.isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
  return 0;
}