#include "common.h"

using namespace std;

class Solution {
 public:
  map<int, bool> memo;
  int used;
  int maxChoosableInteger;
  bool canIWin(int maxChoosableInteger, int desiredTotal) {
    int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;
    if (desiredTotal < 2)
      return true;
    else if (sum < desiredTotal)
      return false;
    else if (sum == desiredTotal)
      return maxChoosableInteger % 2;
    this->maxChoosableInteger = maxChoosableInteger;
    return help(desiredTotal);
  }

  bool help(int desire) {
    if (memo.count(used)) {
      return memo[used];
    }
    bool res = false;
    for (size_t i = 1; i <= maxChoosableInteger; i++) {
      if ((used >> i) & 1) {
        continue;
      }
      if (i >= desire) {
        res = true;
        break;
      }
      used |= 1 << i;
      bool ret = help(desire - i);
      used &= ~(1 << i);
      if (ret == false) {
        res = true;
        break;
      }
    }
    memo[used] = res;
    return res;
  }
};

int main() {
  Solution s;
  cout << s.canIWin(18, 79) << endl;
  return 0;
}