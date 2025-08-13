#include "common.h"

class Solution {
 public:
  int countArrangement(int n) {
    vector<bool> visit(n + 1, false);
    func(1, visit);
    return count;
  }
  void func(int pos, vector<bool>& visit) {
    if (pos >= visit.size()) {
      count += 1;
      return;
    }
    for (auto i = 1; i < visit.size(); ++i) {
      if (!visit[i] && (i % pos == 0 || pos % i == 0)) {
        visit[i] = true;
        func(pos + 1, visit);
        visit[i] = false;
      }
    }
  }
  int count = 0;
};

int main() {
  Solution s;
  cout << s.countArrangement(1) << endl;
}