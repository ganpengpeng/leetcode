#include <unordered_map>

#include "common.h"

using namespace std;

class Solution {
public:
  unordered_map<string, bool> memo;
  vector<string> rst;

  vector<string> wordBreak(string s, vector<string>& wordDict) {
    unordered_map<char, vector<string>> candidate;
    for (auto& s : wordDict) {
      candidate[s[0]].push_back(s);
    }
    helper(candidate, s, "");
    for (auto& s : rst) {
      s = s.substr(1);
    }
    return rst;
  }

  void helper(unordered_map<char, vector<string>>& candidate, string s, string temp) {
    if (s.length() == 0) {
      rst.push_back(temp);
      return;
    }
    const vector<string>& check = candidate[s[0]];
    for (auto& word : check) {
      string sub_str = s.substr(0, word.size());
      if (sub_str != word) {
        continue;
      }
      helper(candidate, s.substr(word.size()), temp + ' ' + word);
    }
  }
};

int main() {
  Solution s;
  vector<string> strs = {"cat", "cats", "and", "sand", "dog"};
  s.wordBreak("catsanddog", strs);
  return 0;
}
