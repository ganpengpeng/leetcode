#include "common.h"

using namespace std;

class Solution {
 public:
  int numberOfWays(string corridor) {
    set < unsigned long long count = 1;
    int seats = 0;
    for (int i = 0, plants = 0; i < corridor.size(); ++i) {
      if (seats == 2) {
        if (corridor[i] == 'S') {
          // rst.push_back(plants + 1);
          count *= plants + 1;
          count %= 1000000007;
          seats = plants = 0;
        } else {
          plants += 1;
        }
      }
      if (corridor[i] == 'S') {
        seats += 1;
      }
    }
    if (seats != 2) {
      return 0;
    }
    return count;
  }
};

int main() {
  Solution s;
  cout << s.numberOfWays("SSPPSPS") << endl;
  return 0;
}