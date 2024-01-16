#include "common.h"

using namespace std;

class Solution {
 public:
  bool isInterleave(string s1, string s2, string s3) {
    vector<bool> dp(s2.size() + 1);

    if (s1.size() + s2.size() != s3.size())
      return false;

    dp[0] = true;
    for (int i = 0; i <= s1.size(); ++i) {
      for (int j = 0; j <= s2.size(); ++j) {
        int index = i + j - 1;
        if (i > 0) {
          dp[j] = dp[j] && s1[i - 1] == s3[index];
        }
        if (j > 0) {
          dp[j] = dp[j] || dp[j - 1] && s2[j - 1] == s3[index];
        }
      }
    }

    return dp[s2.size()];
  }
};

int main() {
  Solution s;
  cout << s.isInterleave("aabcc", "dbbca", "aadbbcbcac") << endl;
  return 0;
}