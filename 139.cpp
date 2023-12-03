#include <unordered_map>

#include "common.h"

using namespace std;

class Solution {
public:
  unordered_map<string, bool> memo;

  bool wordBreak(string s, vector<string>& wordDict) {
    unordered_map<char, vector<string>> candidate;
    for (auto& s : wordDict) {
      candidate[s[0]].push_back(s);
    }
    return helper(candidate, s);
  }

  bool helper(unordered_map<char, vector<string>>& candidate, string s) {
    if (s.length() == 0) {
      return true;
    }
    if (memo.count(s)) {
      return memo[s];
    }
    int rst = false;
    const vector<string>& check = candidate[s.at(0)];
    for (auto& word : check) {
      string sub_str = s.substr(0, word.size());
      if (sub_str != word) {
        continue;
      }
      if (helper(candidate, s.substr(word.size()))) {
        rst = true;
        break;
      }
    }
    memo[s] = rst;
    return rst;
  }
};

int main() {
  Solution s;
  vector<string> strs;
  s.wordBreak("", strs);
  return 0;
}
