#include "common.h"

using namespace std;

class Solution {
 public:
  bool IsSubStr(string& s1, string& s2) {
    int i = 0;
    int j = 0;
    while (i < s1.size() && j < s2.size()) {
      if (s1[i] == s2[j]) {
        i += 1;
      }
      j += 1;
    }
    return i == s1.size();
  }
  int findLUSlength(vector<string>& strs) {
    map<string, int> counts;
    for (string& s : strs) {
      counts[s] += 1;
    }
    vector<pair<string, int>> v;
    for (auto& entry : counts) {
      v.emplace_back(entry.first, entry.second);
    }
    sort(v.begin(), v.end(), [](auto& p1, auto& p2) {
      if (p1.second == p2.second) {
        return p1.first.size() > p2.first.size();
      }
      return p1.second > p2.second;
    });
    for (int i = 0; i < v.size(); ++i) {
      if (counts[v[i].first] > 1) {
        continue;
      }
      int j = 0;
      for (; j < i; ++j) {
        if (IsSubStr(v[i].first, v[j].first)) {
          break;
        }
      }
      if (j == i) {
        return v[i].first.size();
      }
    }
    return -1;
  }
};

int main() {
  Solution s;
  vector<string> v = {"aabbcc", "aabbcc", "cb", "abc", "mmnnqq"};
  cout << s.findLUSlength(v) << endl;
  return 0;
}