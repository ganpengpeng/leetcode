#include "common.h"

using namespace std;

class Solution {
 public:
  const int mod = 1000000007;
  int sumSubarrayMins(vector<int>& arr) {
    arr.insert(arr.begin(), 0);
    vector<uint64_t> rst(arr.size(), 0);
    stack<int> s;
    s.push(0);
    for (int i = 0; i < arr.size(); ++i) {
      while (!s.empty() && arr[s.top()] > arr[i]) {
        s.pop();
      }
      rst[i] = rst[s.top()] + arr[i] * (i - s.top());
      s.push(i);
    }
    uint64_t n = 0;
    for (const auto& item : rst) {
      n = (n + item) % mod;
    }
    return n;
  }
};

int main() {
  Solution s;
  vector<int> v = {3, 1, 2, 4};
  cout << s.sumSubarrayMins(v) << endl;
  return 0;
}