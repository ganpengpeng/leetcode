#include "common.h"

using namespace std;

class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    vector<int> rst;
    priority_queue<pair<int, int>> q;
    for (auto i = 0; i < k - 1; ++i) {
      q.emplace(nums[i], i);
    }
    for (auto i = k - 1; i < nums.size(); ++i) {
      q.emplace(nums[i], i);
      while (true) {
        auto [num, index] = q.top();
        if (index <= i - k) {
          q.pop();
        } else {
          break;
        }
      }
      rst.push_back(q.top().first);
    }
    return rst;
  }
};

int main() {
  Solution s;
  vector<int> v = {9,10,9,-7,-4,-8,2,-6};
  auto rst = s.maxSlidingWindow(v, 5);
  for (auto i = 0; i < rst.size(); ++i) {
    cout << rst[i] << " ";
  }
  cout << endl;
  return 0;
}