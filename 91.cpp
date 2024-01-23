#include "common.h"

using namespace std;

class Solution {
 public:
  int numDecodings(string s) {
    if (s[0] == '0') return 0;
    int a = 0, b = 1;
    for (int i = 1; i <= s.size(); ++i) {
      int temp = 0;
      if (s[i - 1] != '0') {
        temp += b;
      }
      if (i >= 2 && (s[i - 2] == '1' || s[i - 2] == '2' && s[i - 1] < '7')) {
        temp += a;
      }
      a = b;
      b = temp;
    }
    return b;
  }
};

int main() {
  Solution s;
  cout << s.numDecodings("10") << endl;
  return 0;
}