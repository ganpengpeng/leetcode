#include "common.h"

using namespace std;

class Solution {
 public:
  bool uniqueOccurrences(vector<int>& arr) {
    std::map<int, int> count;
    for (const auto &kItem : arr) {
      count[kItem]++;
    }
    std::set<int> s;
    for (const auto &kItem : count) {
      if (s.find(kItem.second) != s.end()) {
        return false;
      }
      s.insert(kItem.second);
    }
    return true;
  }
};

int main() {
  Solution s;
  vector<int> v;
  cout << s.uniqueOccurrences(v) << endl;
  return 0;
}