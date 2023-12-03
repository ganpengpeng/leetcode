#include "common.h"

using namespace std;

class Solution {
public:
  int reverse(int x) {
    int sign = (x & 1 << 31) != 0;
    unsigned rst = 0;
    if (x == INT_MIN)
      return 0;
    x = std::abs(x);
    while (x != 0) {
      int remain = x % 10;
      if (rst > INT_MAX / 10)
        return 0;
      rst = rst * 10 + remain;
      x /= 10;
    }
    if (sign) {
      return -int(rst);
    } else {
      return int(rst);
    }
  }
};

int main() {
  Solution s;
  cout << s.reverse(-2147483412) << endl;
  return 0;
}
