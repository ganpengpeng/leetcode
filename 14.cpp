#include "common.h"

using namespace std;

class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    int pos = -1;
    for (int i = 0; i < strs[0].size(); ++i) {
      for (int j = 0; j < strs.size() - 1; ++j) {
        if (i >= strs[j].size() || i >= strs[j + 1].size() || strs[j][i] != strs[j + 1][i]) {
          if (pos == -1)
            return "";
          return strs[0].substr(0, pos + 1);
        }
      }
      pos += 1;
    }
    return strs[0];
  }
};

int main() {
  Solution s;

  return 0;
}