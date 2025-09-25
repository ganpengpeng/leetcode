#include "common.h"

using namespace std;

class Solution {
 public:
  int trap(vector<int>& height) {
    int n = height.size();
    int res = 0;
    vector<int> s;
    for (int i = 0; i < height.size(); ++i) {
      while (!s.empty() && height[i] > height[s.back()]) {
        int top = s.back();
        s.pop_back();
        int top_left;
        if (s.empty()) {
          break;
        }
        top_left = s.back();
        res += (i - top_left - 1) * (min(height[i], height[top_left]) - height[top]);
      }
      s.push_back(i);
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> intervals = {4,2,0,3,2,5};
  cout << s.trap(intervals) << endl;
  return 0;
}