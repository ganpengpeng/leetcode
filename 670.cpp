#include "common.h"

using namespace std;

class Solution {
 public:
  int maximumSwap(int num) {
    int temp = num;
    vector<int> n;
    while (num) {
      n.push_back(num % 10);
      num /= 10;
    }
    std::reverse(n.begin(), n.end());
    if (n.size() <= 1) {
      return temp;
    }

    int l = 0, r = 0;
    // find first reverse pair
    for (int i = 1; i < n.size(); ++i) {
      if (n[i] > n[i - 1]) {
        l = i - 1;
        r = i;
        break;
      }
    }
    if (r != 0) {
      // found reverse pair, then find largest num after pair
      for (int i = r + 1; i < n.size(); ++i) {
        if (n[i] >= n[r]) {
          r = i;
        }
      }
    }
    // find most left num smaller than n[r]
    while (l > 0 && n[l - 1] < n[r]) {
      l -= 1;
    }
    std::swap(n[l], n[r]);
    int rst = 0;
    for (int i = 0; i < n.size(); ++i) {
      rst = rst * 10 + n[i];
    }
    return rst;
  }
};

int main() {
  Solution s;
  cout << s.maximumSwap(2736) << endl;
  return 0;
}