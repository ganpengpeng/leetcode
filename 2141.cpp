#include "common.h"

using namespace std;

/*class Solution {
 public:
  long long maxRunTime(int n, vector<int>& batteries) {
    priority_queue<int> q(batteries.begin(), batteries.end());
    int rst = 0;
    while (true) {
      if (q.size() < n) {
        break;
      }
      priority_queue<int> temp;
      for (int i = 0; i < n; ++i) {
        auto top = q.top();
        q.pop();
        if (top > 1) {
          temp.push(top - 1);
        }
      }
      rst += 1;
      for (; temp.size();) {
        q.push(temp.top());
        temp.pop();
      }
    }
    return rst;
  }
};*/

class Solution {
 public:
  long long maxRunTime(int n, vector<int>& b) {
    long long low = 1;
    long long high = accumulate(begin(b), end(b), 0LL) / n;

    while (low < high) {
      long long mid = (high + low + 1) / 2;
      long long time = 0;
      for (int t : b) time += min((long long)t, mid);

      if (mid * n <= time)
        low = mid;
      else
        high = mid - 1;
    }
    return low;
  }
};

int main() {
  Solution s;
  vector<int> v = {4, 3, 3, 5};
  cout << s.maxRunTime(3, v) << endl;
  return 0;
}