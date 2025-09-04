#include "common.h"

class Solution {
 public:
  int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
    for (auto i = 0; i < capacity.size(); ++i) {
      capacity[i] -= rocks[i];
    }
    sort(capacity.begin(), capacity.end());
    int sum = 0;
    int res = 0;
    for (auto i = 0; i < capacity.size(); ++i) {
      sum += capacity[i];
      if (sum > additionalRocks) {
        res = i;
        break;
      }
    }
    if (sum <= additionalRocks) {
      res = capacity.size();
    }
    return res;
  }
};
