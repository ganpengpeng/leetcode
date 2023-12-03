#include "common.h"

using namespace std;

class Solution {
  vector<Solution*> childrens;
  bool leaf;

public:
  Solution()
    : childrens(26), leaf(false) {
  }

  vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
    remove_if(words.begin(), words.end(), [](string& s) {
      return s.empty();
    });
    sort(words.begin(), words.end(), [](string& s1, string& s2) {
      return s1.size() < s2.size();
    });
    vector<string> rst;
    for (int i = 0; i < words.size(); ++i) {
      if (helper(words[i], true)) {
        rst.push_back(words[i]);
      }
    }
    return rst;
  }

  bool helper(string& word, bool insert) {
    auto* node = this;
    for (int i = 0; i < word.size(); ++i) {
      int index = word[i] - 'a';
      if (node->childrens[index] == nullptr) {
        if (!insert) {
          return false;
        }
        node->childrens[index] = new Solution;
      }
      node = node->childrens[index];
      if (node->leaf) {
        if (i + 1 == word.size()) {
          return true;
        }
        string sub_str = word.substr(i + 1);
        if (helper(sub_str, false)) {
          return true;
        }
      }
    }
    if (insert) { node->leaf = true; }
    return false;
  }
};

int main() {
  Solution s;
  vector<string> v = {"cat", "cats", "catsdogcats", "dog", "dogcatsdog", "hippopotamuses", "rat", "ratcatdogcat"};
  auto rst = s.findAllConcatenatedWordsInADict(v);
  cout << "[";
  for (auto& s : rst) {
    cout << "\"" << s << "\", ";
  }
  cout << "]" << endl;
  return 0;
}
