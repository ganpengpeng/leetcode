#include "common.h"

class Solution {
 public:
  bool reorderedPowerOf2(int n) {
    vector<int> a;
    int t = n;
    while (t) {
      a.push_back(t % 10);
      t /= 10;
    }
    std::sort(a.begin(), a.end());
    n = 0;
    for (int i = a.size() - 1; i >= 0; --i) {
      n = n * 10 + a[i];
    }
    int m = 1;
    while (m <= n) {
      vector<int> b;
      int k = m;
      while (k) {
        b.push_back(k % 10);
        k /= 10;
      }
      std::sort(b.begin(), b.end());
      if (IsVectorEqual(a, b)) {
        return true;
      }
      m <<= 1;
    }
    return false;
  }

  bool IsVectorEqual(const vector<int>& a, const vector<int>& b) {
    if (a.size() != b.size()) {
      return false;
    }
    for (auto i = 0; i < a.size(); ++i) {
      if (a[i] != b[i]) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  Solution s;
  cout << s.reorderedPowerOf2(46) << endl;
}