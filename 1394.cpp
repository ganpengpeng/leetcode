#include "common.h"

class Solution {
 public:
  int findLucky(vector<int> arr) {
    vector<int> v(501, 0);
    for (const auto& item : arr) {
      v[item] += 1;
    }
    int ans = -1;
    for (const auto& item : arr) {
      if (v[item] == item && item > ans) {
        ans = item;
      }
    }
    return ans;
  }
};

int main() {
  Solution s;
  vector<int> v;
  cout << s.findLucky({}) << endl;
  return 0;
}